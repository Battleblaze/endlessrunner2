// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plattforms.generated.h"

UCLASS()
class ENDLESSRUNNER2_API APlattforms : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
		TArray<UStaticMeshComponent*> Plattforms;

	UPROPERTY(EditAnywhere)
		int AmountOfPlattforms = 10;

	UPROPERTY(EditAnywhere)
		float PlattformGap = 100.f;

	UPROPERTY(EditAnywhere)
		float Speed = 10.f;

	UPROPERTY(EditAnywhere)
		float Width = 500.f;

	UPROPERTY(EditDefaultsOnly)
		UStaticMesh* PlattformMesh;

	UPROPERTY(EditDefaultsOnly)
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
		int LastHealth = 3;

	UFUNCTION(BlueprintCallable)
		void SpawnPlattforms();

	UFUNCTION(BlueprintCallable)
		void RandomizePlattforms();
public:	
	// Sets default values for this actor's properties
	APlattforms();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
