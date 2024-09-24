// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "AISportsCarPawn.h"
#include "GameFramework/Actor.h"
#include "AIStructs.h"
#include "AIGoal.generated.h"

UCLASS(ClassGroup = (Custom),meta = (BlueprintSpawnableComponent), Blueprintable)
class CMP_304_COURSEWORK__API AAIGoal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAIGoal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Box Collision
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UBoxComponent* AiCollision;

	//Function for overlap events
	UFUNCTION() void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
