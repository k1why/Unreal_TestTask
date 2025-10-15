// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Core/DataShareInterface.h"
#include "../Settings/CommonTypes.h"
#include "AbstractActor.generated.h"

class UStaticMeshComponent;
class UMaterialInstanceDynamic;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTERACTIVEOBJECTMANAGER_API AAbstractActor : public AActor, public IDataShareInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbstractActor();

	UFUNCTION(BlueprintCallable)
	void SetActorData(const FActorData& InData);

	UFUNCTION(BlueprintCallable)
	FActorData GetActorData() const;
	
	FSharedData ShareData_Implementation();

protected:
	void UpdateScale(const float InScale);
	void UpdateColor(const FLinearColor& InColor);

	void PostActorCreated() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Settings")
	FActorData Data;

	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(EditAnywhere, Category="Material")
	TObjectPtr<UMaterialParameterCollection> MaterialParamCollection;

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> Material;
};
