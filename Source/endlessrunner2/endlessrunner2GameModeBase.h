// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Algo/Sort.h"
#include "endlessrunner2GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER2_API Aendlessrunner2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	Aendlessrunner2GameModeBase();


	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
		int health = 3;

	UFUNCTION(BlueprintNativeEvent)
		void SaveGameEvent();

	UFUNCTION(BlueprintCallable)
		void SetHighScore();

	UFUNCTION(BlueprintCallable)
		TArray<float> SortArray(TArray<float> ArrayToSort);


	int GetHealth();

	void SubtractOneHealth();

	UPROPERTY(BlueprintReadOnly)
		float score = 0;

	UPROPERTY(BlueprintReadOnly)
		float highScore = 0;
	
};
