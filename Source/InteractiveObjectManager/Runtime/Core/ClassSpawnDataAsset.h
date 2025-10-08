// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../Settings/CommonTypes.h"
#include "../Actors/AbstractActor.h"
#include "ClassSpawnDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTIVEOBJECTMANAGER_API UClassSpawnDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TMap<ESpawnPrimitiveType, TSubclassOf<AAbstractActor>> SpawnedActorClasses;
};
