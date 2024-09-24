// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGoal.h"

// Sets default values
AAIGoal::AAIGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Sets up box and binds function to the begin overlap
	AiCollision = CreateDefaultSubobject<UBoxComponent>(FName("Ai Collision"));
	AiCollision->OnComponentBeginOverlap.AddDynamic(this, &AAIGoal::OnBoxBeginOverlap);
	AiCollision->InitBoxExtent(FVector(300, 32, 900));
	AiCollision->SetBoxExtent(FVector(300, 32, 900));
	AiCollision->SetLineThickness(10);

}

// Called when the game starts or when spawned
void AAIGoal::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAIGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAIGoal::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Gets reference to car
	AAISportsCarPawn* carRef = Cast<AAISportsCarPawn>(OtherActor);

	//If cast is a success
	if (carRef != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Cast Success"));

		//Adds one score to car
		FAIStruct aiStruct = carRef->getAiStruct();
		aiStruct.score += 1;
		carRef->setAIStruct(aiStruct);
		
	}
	else
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Cast Failed"));
	}

}

