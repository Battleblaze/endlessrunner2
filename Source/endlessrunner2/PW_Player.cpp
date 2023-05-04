// Fill out your copyright notice in the Description page of Project Settings.


#include "PW_Player.h"
#include "endlessrunner2GameModeBase.h"
#include "AI/NavigationSystemBase.h"

#include "Blueprint/UserWidget.h"

// Sets default values
APW_Player::APW_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(Mesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);


}



// Called when the game starts or when spawned
void APW_Player::BeginPlay()
{
	Super::BeginPlay();

	Mesh->SetSimulatePhysics(true);
	Mesh->BodyInstance.bNotifyRigidBodyCollision = true;
	Mesh->OnComponentHit.AddDynamic(this, &APW_Player::OnMeshHit);

	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(false);

}

// Called every frame
void APW_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APW_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAction("JumpAction", IE_Pressed, this, &APW_Player::Jump);
}

void APW_Player::Jump()
{
	Mesh->BodyInstance.SetLinearVelocity(FVector::UpVector * Force, false);
	hasBeenHit = false;
}

void APW_Player::OnMeshHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{

	Aendlessrunner2GameModeBase* GameMode = Cast<Aendlessrunner2GameModeBase>(GetWorld()->GetAuthGameMode());
	FString HitActorName = OtherActor->GetFName().ToString();
	if (hasBeenHit==false)
	{
		GameMode->SubtractOneHealth();
		hasBeenHit = true;
		if (GameMode->GetHealth() == 0)
		{
			GameMode->SetHighScore();
			GameMode->SaveGameEvent();


			GetWorld()->GetFirstPlayerController()->Pause();

			UUserWidget* WdgRestart = CreateWidget<UUserWidget>(GetGameInstance(), WidgetClass);
			WdgRestart->AddToViewport();

			GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
			GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
		}
	}
	
	

}
