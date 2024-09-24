// Fill out your copyright notice in the Description page of Project Settings.


#include "Trainer.h"

// Sets default values
ATrainer::ATrainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATrainer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrainer::BestAICheck(AAISportsCarPawn* carRef)
{
	//stores new best ai
	FBestAiStruct newBest;

	//Gets reference to gamemode
	AAiGameModeBase* gameModeRef = Cast<AAiGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	//If current car has a score greater than 1
	if (carRef->getAiStruct().score > 1)
	{
		//Set best ai found true
		gameModeRef->SetBestAIFound(true);

		//If score is beter than stored score
		if (carRef->getAiStruct().score > gameModeRef->GetBestAI().bestAI0.score)
		{
			//update stored ai 
			newBest.bestAI0 = carRef->getAiStruct();
			newBest.bestAI1 = gameModeRef->GetBestAI().bestAI1;
			newBest.bestAI2 = gameModeRef->GetBestAI().bestAI2;
			gameModeRef->SetBestAI(newBest);
		}
		//If score is beter than stored score
		else if (carRef->getAiStruct().score > gameModeRef->GetBestAI().bestAI1.score)
		{
			//update stored ai 
			newBest.bestAI0 = gameModeRef->GetBestAI().bestAI0;
			newBest.bestAI1 = carRef->getAiStruct();
			newBest.bestAI2 = gameModeRef->GetBestAI().bestAI2;
			gameModeRef->SetBestAI(newBest);
		}
		//If score is beter than stored score
		else if (carRef->getAiStruct().score > gameModeRef->GetBestAI().bestAI2.score)
		{
			//update stored ai 
			newBest.bestAI0 = gameModeRef->GetBestAI().bestAI0;
			newBest.bestAI1 = gameModeRef->GetBestAI().bestAI1;
			newBest.bestAI2 = carRef->getAiStruct();
			gameModeRef->SetBestAI(newBest);
		}
	}
}

void ATrainer::CarCleanup()
{
	//Stores all spawned cars
	TArray<AActor*> carArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAISportsCarPawn::StaticClass() , carArray);

	//For ever car
	for (int i = 0; i < carArray.Num(); i++)
	{
		//check if its the best ai
		AAISportsCarPawn* carRef = Cast<AAISportsCarPawn>(carArray[i]);
		BestAICheck(carRef);
	}
	//For every car
	for (int i = 0; i < carArray.Num(); i++)
	{
		//destroy car
		carArray[i]->Destroy();
	}

}

