// Fill out your copyright notice in the Description page of Project Settings.


#include "NRotatingActor.h"
#include "Components/StaticMeshComponent.h"

ANRotatingActor::ANRotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	//생성자에서 생성 안하는게 좋음
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	MeshComp->SetupAttachment(RootComponent);
}

void ANRotatingActor::BeginPlay()
{
	Super::BeginPlay();

	if (bIsRandom)
	{
		SetRandom();
	}

	if (!bIsCircleDirection) 
	{
		RotationSpeed = RotationSpeed * -1;
	}

	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle, 
		FTimerDelegate::CreateLambda([this]()
			{
					Destroy();
			}),
		5.0f, false);
}

void ANRotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator RotationDelta(0.0f, RotationSpeed * DeltaTime, 0.0f);
	AddActorLocalRotation(RotationDelta);

}

void ANRotatingActor::SetRandom()
{
	//a이상 b이하
	RotationSpeed = FMath::RandRange(30.0f, 100.0f);
	bIsCircleDirection = FMath::RandBool();
}

