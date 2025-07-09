// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "NGameMode.generated.h"

/**
 * 
 */
UCLASS()
class NBC_HW06_API ANGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	ANGameMode();

	virtual void StartPlay() override;

	void SpawnRotatingActor();

private:
	FTimerHandle TimerHandle;
};
