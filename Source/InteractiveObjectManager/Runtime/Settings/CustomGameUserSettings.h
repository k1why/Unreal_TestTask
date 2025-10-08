// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "CommonTypes.h"
#include "CustomGameUserSettings.generated.h"

/**
 * 
 */
UCLASS(config = GameUserSettings, configdonotcheckdefaults, Blueprintable)
class INTERACTIVEOBJECTMANAGER_API UCustomGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:
	UCustomGameUserSettings(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintCallable, Category = Settings)
	void SetDefaultObjectType(const ESpawnPrimitiveType NewType);

	UFUNCTION(BlueprintCallable, Category = Settings)
	void SetDefaultColor(const FLinearColor NewColor);

	UFUNCTION(BlueprintCallable, Category = Settings)
	void SetDefaultScale(const float NewScale);

	UFUNCTION(BlueprintPure, Category = Settings)
	ESpawnPrimitiveType GetDefaultObjectType() const;

	UFUNCTION(BlueprintPure, Category = Settings)
	FLinearColor GetDefaultColor() const;

	UFUNCTION(BlueprintPure, Category = Settings)
	float GetDefaultScale() const;

protected:
	UPROPERTY(Config)
	uint8 DefaultObjectType;

	UPROPERTY(Config)
	TArray<float> DefaultObjectColor;

	UPROPERTY(Config)
	float DefaultObjectScale;
};
