// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AiStructs.h"
#include "AiGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CMP_304_COURSEWORK__API AAiGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	
	AAiGameModeBase();

	//Getters / Setters
	UFUNCTION(BlueprintCallable) bool GetBestAIFound();
	UFUNCTION(BlueprintCallable) void SetBestAI(FBestAiStruct newAi);
	UFUNCTION(BlueprintCallable) void SetBestAIFound(bool newBool);
	UFUNCTION(BlueprintCallable) FBestAiStruct GetBestAI();

protected:

	virtual void BeginPlay() override;
	//Structs
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FBestAiStruct BestAIStruct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bestAIFound;

};
