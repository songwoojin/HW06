// Fill out your copyright notice in the Description page of Project Settings.


#include "NActorSpawner.h"
#include "Components/BoxComponent.h"
#include "NRotatingActor.h"

ANActorSpawner::ANActorSpawner()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	BoxComponent->SetupAttachment(RootComponent);
}

void ANActorSpawner::SpawnActor()
{
	FVector Location = GetActorLocation();
	FRotator Rotation = GetActorRotation();

	if (ActorToSpawn)
	{
		AActor* Actor=GetWorld()->SpawnActor<AActor>(ActorToSpawn,Location, Rotation);

		ANRotatingActor* RotatingActor = Cast<ANRotatingActor>(Actor);
		if (RotatingActor)
		{
			RotatingActor->SetRandom();
		}
	}
}

void ANActorSpawner::BeginPlay()
{
	Super::BeginPlay();

	//SpawnActor();
	
}

