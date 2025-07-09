// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NActorSpawner.generated.h"

UCLASS()
class NBC_HW06_API ANActorSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ANActorSpawner();

	void SpawnActor();
protected:
	virtual void BeginPlay() override;

private:
	TObjectPtr<class UBoxComponent> BoxComponent;

	UPROPERTY(EditDefaultsOnly,Category="Setting")
	TSubclassOf<AActor> ActorToSpawn;
};
