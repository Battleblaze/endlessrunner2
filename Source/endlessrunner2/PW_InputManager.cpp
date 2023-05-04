// Fill out your copyright notice in the Description page of Project Settings.


#include "PW_InputManager.h"
#include "PW_Player.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
APW_InputManager::APW_InputManager()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	

}

// Called when the game starts or when spawned
void APW_InputManager::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*>FoundPlayers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), PlayerClass, FoundPlayers);

	if (FoundPlayers.Num() < 2)
	{
		UE_LOG(LogTemp, Error, TEXT("APW_InputManager: Found less than 2 instances of APW_Player!"));
		return;
	}
	
	Player1 = Cast<APW_Player>(FoundPlayers[0]);
	Player2 = Cast<APW_Player>(FoundPlayers[1]);

	UE_LOG(LogTemp, Warning, TEXT("P1"), Player1)
	UE_LOG(LogTemp, Warning, TEXT("P2"), Player2)

	if (!Player1 || !Player2)
	{
		UE_LOG(LogTemp, Error, TEXT("APW_InputManager: Failed to cast actors to APW_Player!"));
		return;
	}
	
}

// Called every frame
void APW_InputManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Mokeeeee"))

}

// Called to bind functionality to input
void APW_InputManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("JumpAction", EInputEvent::IE_Pressed, this, &APW_InputManager::JumpP1);

	PlayerInputComponent->BindAction("JumpAction2", EInputEvent::IE_Pressed, this, &APW_InputManager::JumpP2);

}

void APW_InputManager::JumpP1()
{
	if (Player1)
	{
		Player1->Jump();
		UE_LOG(LogTemp, Warning,TEXT("Jumping"))
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("APW_InputManager: Player1 is null!"));
	}
}

void APW_InputManager::JumpP2()
{
	Player2->Jump();
}

