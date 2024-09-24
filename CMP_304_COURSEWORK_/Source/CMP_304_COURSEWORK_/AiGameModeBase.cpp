// Fill out your copyright notice in the Description page of Project Settings.


#include "AiGameModeBase.h"

AAiGameModeBase::AAiGameModeBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAiGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

bool AAiGameModeBase::GetBestAIFound()
{
	return bestAIFound;
}
void AAiGameModeBase::SetBestAI(FBestAiStruct newAi)
{
	BestAIStruct = newAi;
}

FBestAiStruct AAiGameModeBase::GetBestAI()
{
	return BestAIStruct;
}

void AAiGameModeBase::SetBestAIFound(bool newBool)
{
	bestAIFound = newBool;
}
