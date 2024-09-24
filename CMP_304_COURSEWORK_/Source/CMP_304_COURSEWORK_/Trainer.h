// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AiStructs.h"
#include "AISportsCarPawn.h"
#include "Trainer.generated.h"

UCLASS()
class CMP_304_COURSEWORK__API ATrainer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrainer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//Checks if this ai is the best
	UFUNCTION(BlueprintCallable) void BestAICheck(AAISportsCarPawn* carRef);
	//Checks AI and then destroys all actors
	UFUNCTION(BlueprintCallable) void CarCleanup();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
