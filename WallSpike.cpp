// Fill out your copyright notice in the Description page of Project Settings.


#include "WallSpike.h"

AWallSpike::AWallSpike()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWallSpike::BeginPlay()
{
	Super::BeginPlay();

	this->GetRootComponent()->ComponentVelocity = FVector(0, 75, 0);

}

void AWallSpike::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + FVector(0, 550 * DeltaTime, 0), true); //Can change wall speed here
}
