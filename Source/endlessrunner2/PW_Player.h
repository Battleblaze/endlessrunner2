// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "endlessrunner2GameModeBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Pawn.h"
#include "PW_Player.generated.h"


UCLASS()
class ENDLESSRUNNER2_API APW_Player : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		float Force = 100.0f;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UUserWidget> WidgetClass;

	//UPROPERTY(VisibleAnywhere)
	//	int health = 3;
	UPROPERTY(VisibleAnywhere)
		bool hasBeenHit = false;



public:
	// Sets default values for this pawn's properties
	APW_Player();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Jump();

	UFUNCTION()
		void OnMeshHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
