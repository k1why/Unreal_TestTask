// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectManagerSubsystem.h"

#include "../Actors/CubeActor.h"
#include "../Actors/SphereActor.h"

void UObjectManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UObjectManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

AAbstractActor* UObjectManagerSubsystem::SpawnActor(const FActorData& Data, const FVector& Location)
{
	if (AAbstractActor* Actor = GetWorld()->SpawnActor<AAbstractActor>(GetActorClass(Data.Type), Location, {0.f, 0.f, 0.f}, {}))
	{
		Actor->SetActorData(Data);
		return Actor;
	}
	
	return nullptr;
}

void UObjectManagerSubsystem::DeleteActor(AAbstractActor* Actor)
{
	if (Actor) Actor->Destroy();
}

void UObjectManagerSubsystem::ChangeActor(AAbstractActor* Actor, const FActorData& Data)
{
}

TSubclassOf<AAbstractActor> UObjectManagerSubsystem::GetActorClass(ESpawnPrimitiveType Type) const
{
	switch (Type) {
		case ESpawnPrimitiveType::SPHERE: return ASphereActor::StaticClass();
		case ESpawnPrimitiveType::CUBE: return ACubeActor::StaticClass();
	}

	return TSubclassOf<AAbstractActor>();
}
