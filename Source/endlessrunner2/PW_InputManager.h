// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PW_Player.h"
#include "GameFramework/Pawn.h"
#include "PW_InputManager.generated.h"

UCLASS()
class ENDLESSRUNNER2_API APW_InputManager : public APawn
{
	GENERATED_BODY()


public:
	// Sets default values for this pawn's properties
	APW_InputManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<APW_Player> PlayerClass;

	UPROPERTY();
	TArray<AActor*> Players;

	UPROPERTY();
	APW_Player* Player1;

	UPROPERTY()
	APW_Player* Player2;

private:


	UFUNCTION()
		void JumpP1();

	UFUNCTION()
		void JumpP2();
};

