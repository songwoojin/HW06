// Fill out your copyright notice in the Description page of Project Settings.


#include "NMovingActor.h"

ANMovingActor::ANMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	RootComponent = MeshComp;

	FRotator Adjust = FRotator(0.f, -90.f, 0.f); // Yaw 축 기준 회전 값
	MeshComp->SetRelativeRotation(Adjust);
}

void ANMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();

	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		FTimerDelegate::CreateLambda([this]()
			{
				Destroy();
			}),
		15.0f, false);

	if (bIsRandom)
	{
		SetRandom();
	}
}

void ANMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float Dist = FVector::Distance(StartLocation, GetActorLocation());

	if (Dist >= MaxRange)
	{
		MoveSpeed = MoveSpeed * -1;
		StartLocation = GetActorLocation();

	}
	else
	{
		SetActorLocation(GetActorLocation() + FVector(MoveSpeed * DeltaTime,0.0f,0.0f));
	}
}

void ANMovingActor::SetRandom()
{
	MoveSpeed = FMath::RandRange(150.0f, 250.0f);
	MaxRange = FMath::RandRange(900.0f, 1100.0f);
}

