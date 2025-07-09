// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NRotatingActor.generated.h"

UCLASS()
class NBC_HW06_API ANRotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ANRotatingActor();

protected:
	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly,Category="Mesh",meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(EditAnywhere, Category = "Setting", meta = (AllowPrivateAccess = "true"))
	float RotationSpeed;

	UPROPERTY(EditAnywhere, Category = "Setting", meta = (AllowPrivateAccess = "true"))
	bool bIsCircleDirection;

	FTimerHandle TimerHandle;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Setting", meta = (AllowPrivateAccess = "true"))
	bool bIsRandom;
	
	UFUNCTION(BlueprintCallable)
	void SetRandom();
private:
};
