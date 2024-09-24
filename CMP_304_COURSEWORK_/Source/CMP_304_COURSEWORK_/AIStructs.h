// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIStructs.generated.h"

//Struct to hold all weights
USTRUCT(BlueprintType)
struct FAIWeightStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight7;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight9;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight11;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight12;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight13;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float weight14;

};

//Struct to store information all ai needs - Its weights and its score
USTRUCT(BlueprintType)
struct FAIStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FAIWeightStruct AiWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int score = 0;

};

//Struct to store best ai for direction
USTRUCT(BlueprintType)
struct FBestAiStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FAIStruct bestAI0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FAIStruct bestAI1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FAIStruct bestAI2;


};

