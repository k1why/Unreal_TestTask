// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "../Core/ClassSpawnDataAsset.h"
#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTIVEOBJECTMANAGER_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
	TObjectPtr<UClassSpawnDataAsset> SpawnData;
};
