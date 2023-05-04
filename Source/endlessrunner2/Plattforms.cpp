// Fill out your copyright notice in the Description page of Project Settings.


#include "Plattforms.h"
#include "endlessrunner2GameModeBase.h"

void APlattforms::SpawnPlattforms()
{
	for (size_t i = 0; i <Plattforms.Num(); i++)
	{
		if (Plattforms[i])
		{
			Plattforms[i]->DestroyComponent();
		}
	}
	Plattforms.Empty();

	for (size_t i = 0; i < AmountOfPlattforms; i++)
	{
		UStaticMeshComponent* smc = (UStaticMeshComponent*)AddComponentByClass(UStaticMeshComponent::StaticClass(), false, FTransform(), true);

		if (smc)
		{
			smc->RegisterComponent();
			smc->SetMobility(EComponentMobility::Movable);
			smc->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			smc->SetWorldLocation(this->GetActorLocation() + FVector(0, PlattformGap * i, 0));
			smc->SetStaticMesh(PlattformMesh);
			Plattforms.Add(smc);
		}
	}
	RandomizePlattforms();
}

void APlattforms::RandomizePlattforms()
{
	for (size_t i = 0; i < AmountOfPlattforms; i++)
	{
		Plattforms[i]->SetWorldScale3D(FVector(1, 1, FMath::RandRange(1, 7)));
	}
}

// Sets default values
APlattforms::APlattforms()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

}

// Called when the game starts or when spawned
void APlattforms::BeginPlay()
{
	Super::BeginPlay();

	Speed = 200;
	
}

void APlattforms::OnConstruction(const FTransform& Transform)
{
	SpawnPlattforms();
	Aendlessrunner2GameModeBase* GameMode = Cast<Aendlessrunner2GameModeBase>(GetWorld()->GetAuthGameMode());
}

// Called every frame
void APlattforms::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + FVector(0, -Speed * DeltaTime, 0));
	
	Aendlessrunner2GameModeBase* GameMode = Cast<Aendlessrunner2GameModeBase>(GetWorld()->GetAuthGameMode());

	if (GetActorLocation().Y < -1 * PlattformGap * AmountOfPlattforms + 300)
	{
		
	
		if (GameMode->GetHealth()==LastHealth)
		{
			int randInt = FMath::RandRange(0, 100);//"0% Chance of next segment not spawning if you correctly dodged all plattforms
			if (randInt>20)
			{
				SetActorLocation(GetActorLocation() + FVector(0, PlattformGap * AmountOfPlattforms + Width, 0));
				RandomizePlattforms();
				Speed = Speed + 100;
				LastHealth = GameMode->GetHealth();
			}
		}
		else
		{
			SetActorLocation(GetActorLocation() + FVector(0, PlattformGap * AmountOfPlattforms + Width, 0));
			RandomizePlattforms();
			Speed = Speed + 100;
			LastHealth = GameMode->GetHealth();
		}

			
	}
	if (GetActorLocation().Y < -2 * PlattformGap * AmountOfPlattforms + 300)
	{
		SetActorLocation(GetActorLocation() + FVector(0, 2.5*(PlattformGap * AmountOfPlattforms + Width), 0));
		RandomizePlattforms();
		Speed = Speed + 100;
		LastHealth = GameMode->GetHealth();
	}

}

