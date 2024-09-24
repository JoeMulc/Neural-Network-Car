t// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "AiStructs.h"
#include "Math/UnrealMathUtility.h"
#include "Components/ArrowComponent.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "AiGameModeBase.h"
#include "AISportsCarPawn.generated.h"

/**
 * 
 */
UCLASS()
class CMP_304_COURSEWORK__API AAISportsCarPawn : public AWheeledVehiclePawn
{
	GENERATED_BODY()
	
public:

	//Getters/setters
	UFUNCTION() void setTraceLength(float tL);
	UFUNCTION() float getTraceLength();
	UFUNCTION() void setAIStruct(FAIStruct newAI);
	UFUNCTION() FAIStruct getAiStruct();

protected:
	//Length of line trace
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float traceLength = 16000.f;

	//Struct to hold AI's values
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FAIStruct AIStruct;

	//Distance to wall of all arrows
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float NWDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float NDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float NEDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float EDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float WDistance;

	//Direction to steer in
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float steerDirection;

	//Returns struct full of random weight values
	UFUNCTION(BlueprintCallable) void InitWeight();

	//Returns Randomised weights
	UFUNCTION(BlueprintCallable) FAIWeightStruct GetRandomWeights();

	//Improves cars weights based on best weight
	UFUNCTION(BlueprintCallable) FAIWeightStruct ImproveWeight(FBestAiStruct bestAI);

	//Trace for one of cars sensors
	UFUNCTION(BlueprintCallable) float CarVisionTrace(UArrowComponent* arrowRef);

	//Sigmoid function
	UFUNCTION(BlueprintCallable) float SigmoidFunction(float input);

	//Neuron
	UFUNCTION(BlueprintCallable) float NetworkNeuron(float weight0, float weight1, float weight2, float weight3, float weight4);

	//Neural network
	UFUNCTION(BlueprintCallable) void AINeuralNetwork();

};
