// Fill out your copyright notice in the Description page of Project Settings.


#include "NRotatingActor.h"
#include "Components/StaticMeshComponent.h"

ANRotatingActor::ANRotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	//�����ڿ��� ���� ���ϴ°� ����
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
	//a�̻� b����
	RotationSpeed = FMath::RandRange(30.0f, 100.0f);
	bIsCircleDirection = FMath::RandBool();
}

