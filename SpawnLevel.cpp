// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnLevel.h"

#include "BaseLevel.h"
#include "Engine.h"
#include "Components/BoxComponent.h"


// Sets default values
ASpawnLevel::ASpawnLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnLevel::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnLevel(true);
	SpawnLevel(false);
	SpawnLevel(false);
	SpawnLevel(false);
}

// Called every frame
void ASpawnLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnLevel::SpawnLevel(bool IsFirst)
{

	SpawnLocation = FVector(0.0f, 1000.0f, 0.0f);
	SpawnRotation = FRotator(0, 90, 0);

	if (!IsFirst) //Spawns the level on the spawn locaiton set on the blueprint in unreal
	{
		ABaseLevel* LastLevel = LevelList.Last();
		SpawnLocation = LastLevel->GetSpawnLocation()->GetComponentTransform().GetTranslation();
	}

	//Chooose a level randomly
	RandomLevel = FMath::RandRange(1, 10);
	ABaseLevel* NewLevel = nullptr;

	if (RandomLevel == 1)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level1,
			SpawnLocation, SpawnRotation, SpawnInfo);
	} 
	else if (RandomLevel == 2)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level2,
			SpawnLocation, SpawnRotation, SpawnInfo);
	} 
	else if (RandomLevel == 3)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level3,
			SpawnLocation, SpawnRotation, SpawnInfo);
	} 
	else if (RandomLevel == 4)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level4,
			SpawnLocation, SpawnRotation, SpawnInfo);
	} 
	else if (RandomLevel == 5)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level5,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 6)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level6,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 7)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level7,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 8)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level8,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 9)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level9,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level10,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}

	if (NewLevel)
	{
		if (NewLevel->GetTrigger())
		{
			NewLevel->GetTrigger()->OnComponentBeginOverlap.AddDynamic(this, &ASpawnLevel::OnOverlapBegin); //When we collide with the Trigger to spawn a new level, the new level will spawn
		}
	}

	LevelList.Add(NewLevel);
	if (LevelList.Num() > 5) //If there are more than 5 levels in the list we are going to remove the last element
	{
		LevelList.RemoveAt(0);
	}
}

void ASpawnLevel::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	SpawnLevel(false);
}

