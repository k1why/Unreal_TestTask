// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "../Actors/AbstractActor.h"
#include "ClassSpawnDataAsset.h"
#include "ObjectManagerSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FManagerSubsystemDelegate);

UCLASS()
class INTERACTIVEOBJECTMANAGER_API UObjectManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UFUNCTION(BlueprintCallable)
	AAbstractActor* SpawnActor(const FActorData& Data, const FVector& Location);

	UFUNCTION(BlueprintCallable)
	void DeleteActor(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	AAbstractActor* ChangeActor(AAbstractActor* Actor, const FActorData& Data);

	UFUNCTION(BlueprintCallable)
	void OnINIFileError(const UObject* Caller, const FString Error);

protected:
	TSubclassOf<AAbstractActor> GetActorClass(ESpawnPrimitiveType Type) const;

protected:
	UPROPERTY()
	TObjectPtr<UClassSpawnDataAsset> DataAsset;
};
