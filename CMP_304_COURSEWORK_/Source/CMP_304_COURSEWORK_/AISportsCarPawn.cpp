// Fill out your copyright notice in the Description page of Project Settings.


#include "AISportsCarPawn.h"


void AAISportsCarPawn::setTraceLength(float tL)
{
	traceLength = tL;
}

float AAISportsCarPawn::getTraceLength()
{
	return traceLength;
}


void AAISportsCarPawn::setAIStruct(FAIStruct newAI)
{
	AIStruct = newAI;
}

FAIStruct AAISportsCarPawn::getAiStruct()
{
	return AIStruct;
}


//Gets random weights for initial car spawn
FAIWeightStruct AAISportsCarPawn::GetRandomWeights()
{
	FAIWeightStruct randWeights;

	//Sets weight to a random float between 0 and 1
	randWeights.weight0 = FMath::RandRange(0.f, 1.f);
	randWeights.weight1 = FMath::RandRange(0.f, 1.f);
	randWeights.weight2 = FMath::RandRange(0.f, 1.f);
	randWeights.weight3 = FMath::RandRange(0.f, 1.f);
	randWeights.weight4 = FMath::RandRange(0.f, 1.f);
	randWeights.weight5 = FMath::RandRange(0.f, 1.f);
	randWeights.weight6 = FMath::RandRange(0.f, 1.f);
	randWeights.weight7 = FMath::RandRange(0.f, 1.f);
	randWeights.weight8 = FMath::RandRange(0.f, 1.f);
	randWeights.weight9 = FMath::RandRange(0.f, 1.f);
	randWeights.weight10 = FMath::RandRange(0.f, 1.f);
	randWeights.weight11 = FMath::RandRange(0.f, 1.f);
	randWeights.weight12 = FMath::RandRange(0.f, 1.f);
	randWeights.weight13 = FMath::RandRange(0.f, 1.f);
	randWeights.weight14 = FMath::RandRange(0.f, 1.f);

	return randWeights;
}

//Improves weights based off one of the best AI
FAIWeightStruct AAISportsCarPawn::ImproveWeight(FBestAiStruct bestAI)
{
	//Stores newWeights
	FAIWeightStruct newWeight;

	//Creates array of best AI
	TArray<FAIStruct> bestAiArray;
	bestAiArray.Add(bestAI.bestAI0);
	bestAiArray.Add(bestAI.bestAI1);
	bestAiArray.Add(bestAI.bestAI2);

	//Gets random best ai
	FAIStruct randAi;
	randAi = bestAiArray[FMath::RandRange(0, 2)];

	//Assigns best ais weights to this car
	newWeight.weight0 = FMath::Clamp((randAi.AiWeight.weight0 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight1 = FMath::Clamp((randAi.AiWeight.weight1 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight2 = FMath::Clamp((randAi.AiWeight.weight2 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight3 = FMath::Clamp((randAi.AiWeight.weight3 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight4 = FMath::Clamp((randAi.AiWeight.weight4 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight5 = FMath::Clamp((randAi.AiWeight.weight5 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight6 = FMath::Clamp((randAi.AiWeight.weight6 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight7 = FMath::Clamp((randAi.AiWeight.weight7 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight8 = FMath::Clamp((randAi.AiWeight.weight8 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight9 = FMath::Clamp((randAi.AiWeight.weight9 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight10 = FMath::Clamp((randAi.AiWeight.weight10 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight11 = FMath::Clamp((randAi.AiWeight.weight11 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight12 = FMath::Clamp((randAi.AiWeight.weight12 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight13 = FMath::Clamp((randAi.AiWeight.weight13 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);
	newWeight.weight14 = FMath::Clamp((randAi.AiWeight.weight14 * FMath::RandRange(0.8f, 1.2f)), 0.f, 1.f);

	return newWeight;

}

float AAISportsCarPawn::CarVisionTrace(UArrowComponent* arrowRef)
{
	//Trace setup
	FCollisionQueryParams traceParams = FCollisionQueryParams(FName(TEXT("Car Trace")), true, this);
	traceParams.bTraceComplex = true;
	traceParams.bDebugQuery = true;
	FHitResult traceHit;

	//Trace start and end
	FVector start = arrowRef->GetComponentLocation();
	FVector end = (arrowRef->GetForwardVector() * traceLength) + start;

	//Line trace
	GetWorld()->LineTraceSingleByChannel(traceHit, start, end, ECC_Visibility, traceParams);
	//Debug
	//DrawDebugLine(
	//	GetWorld(),
	//	start,
	//	traceHit.Location,
	//	FColor(255, 0, 0),
	//	false, -1, 0,
	//	12.333
	//);

	//Returns distance to wall
	return traceHit.Distance;
}

float AAISportsCarPawn::SigmoidFunction(float input)
{
	return 1 / (FMath::Pow(EULERS_NUMBER, input) + 1);
}

float AAISportsCarPawn::NetworkNeuron(float weight0, float weight1, float weight2, float weight3, float weight4)
{
	float probability;


	probability = (NWDistance * weight0) + (NDistance * weight1) + (NEDistance * weight2) + (EDistance * weight3) + (WDistance * weight4);
	probability = probability / 100;

	//Returns the probability that the ai should use these weights
	return SigmoidFunction(probability);
}

void AAISportsCarPawn::InitWeight()
{
	FAIStruct newAI;

	//Gets reference to game mode
	AAiGameModeBase* gameModeRef = Cast<AAiGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	//IF the best ai has been found
	if (gameModeRef->GetBestAIFound())
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Best Ai found"));
	
		//Get improved weights
		newAI.AiWeight = ImproveWeight(gameModeRef->GetBestAI());
	}
	else
	{
		//Get random weights
		newAI.AiWeight = GetRandomWeights();
	}

	//Sets weight to determined weight and resets score
	AIStruct.AiWeight = newAI.AiWeight;
	AIStruct.score = 0.f;
}

void AAISportsCarPawn::AINeuralNetwork()
{
	float probability0, probability1, probability2;

	//Calculates probability of each direction
	probability0 = NetworkNeuron(AIStruct.AiWeight.weight0, AIStruct.AiWeight.weight1, AIStruct.AiWeight.weight2, AIStruct.AiWeight.weight3, AIStruct.AiWeight.weight4);
	probability1 = NetworkNeuron(AIStruct.AiWeight.weight5, AIStruct.AiWeight.weight6, AIStruct.AiWeight.weight7, AIStruct.AiWeight.weight8, AIStruct.AiWeight.weight9);
	probability2 = NetworkNeuron(AIStruct.AiWeight.weight10, AIStruct.AiWeight.weight11, AIStruct.AiWeight.weight12, AIStruct.AiWeight.weight13, AIStruct.AiWeight.weight14);

	//Creates array of probabilities
	TArray<float> probArray;
	probArray.Add(probability0);
	probArray.Add(probability1);
	probArray.Add(probability2);

	//Gets index of highest probability
	int index;
	float maxVal;
	UKismetMathLibrary::MaxOfFloatArray(probArray, index, maxVal);

	//Steers in direction based off the highest probability
	switch (index)
	{
	case 0:
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Left"));
		steerDirection = 1.f;
		break;
	case 1:
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Straight"));
		steerDirection = 0.f;
		break;
	case 2:
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Right"));
		steerDirection = -1.f;
		break;
	default:
		break;
	}

}