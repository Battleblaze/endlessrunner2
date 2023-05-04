// Copyright Epic Games, Inc. All Rights Reserved.


#include "endlessrunner2GameModeBase.h"
#include "Algo/Sort.h"

Aendlessrunner2GameModeBase::Aendlessrunner2GameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;


}

void Aendlessrunner2GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	score += DeltaTime;

	UE_LOG(LogTemp, Warning, TEXT("Score is %f "), score);
}

void Aendlessrunner2GameModeBase::SaveGameEvent_Implementation()
{

}

void Aendlessrunner2GameModeBase::SetHighScore()
{
	highScore = score;
}

TArray<float> Aendlessrunner2GameModeBase::SortArray(TArray<float> ArrayToSort)
{
	Algo::Sort(ArrayToSort);
	return ArrayToSort;
}

int Aendlessrunner2GameModeBase::GetHealth()
{
	return health;
}

void Aendlessrunner2GameModeBase::SubtractOneHealth()
{
	health--;
}

