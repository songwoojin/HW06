// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NMovingActor.generated.h"

UCLASS()
class NBC_HW06_API ANMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ANMovingActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> MeshComp;

	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "Setting", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed;

	UPROPERTY(EditAnywhere, Category = "Setting", meta = (AllowPrivateAccess = "true"))
	float MaxRange;
	
	UPROPERTY(EditAnywhere, Category = "Setting", meta = (AllowPrivateAccess = "true"))
	bool bIsRandom;

	FTimerHandle TimerHandle;
private:
	void SetRandom();
};
