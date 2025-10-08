// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectManagerSubsystem.h"
#include "../GameCommon/CustomGameInstance.h"

void UObjectManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	TObjectPtr<UCustomGameInstance> GI = Cast<UCustomGameInstance>(GetGameInstance());
	DataAsset = GI->SpawnData;
}

void UObjectManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

AAbstractActor* UObjectManagerSubsystem::SpawnActor(const FActorData& Data, const FVector& Location)
{
	if (!IsValid(DataAsset)) return nullptr;
	
	if (AAbstractActor* Actor = GetWorld()->SpawnActor<AAbstractActor>(GetActorClass(Data.Type), Location, {0.f, 0.f, 0.f}, {}))
	{
		Actor->SetActorData(Data);
		return Actor;
	}
	
	return nullptr;
}

void UObjectManagerSubsystem::DeleteActor(AActor* Actor)
{
	if (Actor) Actor->Destroy();
}

AAbstractActor* UObjectManagerSubsystem::ChangeActor(AAbstractActor* Actor, const FActorData& Data)
{
	FActorData OldData = Actor->GetActorData();
	if (OldData.Type != Data.Type)
	{
		FVector Location = Actor->GetActorLocation();
		DeleteActor(Actor);
		
		return SpawnActor(Data, Location);
	}

	Actor->SetActorData(Data);
	return nullptr;
}

TSubclassOf<AAbstractActor> UObjectManagerSubsystem::GetActorClass(ESpawnPrimitiveType Type) const
{
	return *DataAsset->SpawnedActorClasses.Find(Type);
}
