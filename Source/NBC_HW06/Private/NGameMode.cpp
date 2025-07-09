// Fill out your copyright notice in the Description page of Project Settings.


#include "NGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "NActorSpawner.h"

ANGameMode::ANGameMode()
{
}

void ANGameMode::StartPlay()
{
	Super::StartPlay();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this]() {
		SpawnRotatingActor();
	}), 6.0f, true);

}

void ANGameMode::SpawnRotatingActor()
{
	TArray<AActor*>FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANActorSpawner::StaticClass(), FoundActors);

	int32 RandNum = FMath::RandRange(0, FoundActors.Num() - 1);

	ANActorSpawner* Spawner = Cast<ANActorSpawner>(FoundActors[RandNum]);
	if (Spawner)
	{
		Spawner->SpawnActor();
	}
}
