// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameUserSettings.h"

#include "ViewportWorldInteraction.h"

UCustomGameUserSettings::UCustomGameUserSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetDefaultObjectType(ESpawnPrimitiveType::CUBE);
	SetDefaultColor(FLinearColor::Red);
	SetDefaultScale(2.f);
}

void UCustomGameUserSettings::SetDefaultObjectType(const ESpawnPrimitiveType NewType)
{
	DefaultObjectType = static_cast<uint8>(NewType);
}

void UCustomGameUserSettings::SetDefaultColor(const FLinearColor NewColor)
{
	DefaultObjectColor = TArray<float>{NewColor.R, NewColor.G, NewColor.B, NewColor.A};
}

void UCustomGameUserSettings::SetDefaultScale(const float NewScale)
{
	DefaultObjectScale = NewScale;
}

ESpawnPrimitiveType UCustomGameUserSettings::GetDefaultObjectType() const
{
	return static_cast<ESpawnPrimitiveType>(DefaultObjectType);
}

FLinearColor UCustomGameUserSettings::GetDefaultColor() const
{
	return DefaultObjectColor.IsEmpty() ? (FLinearColor::Blue) : FLinearColor{DefaultObjectColor[0], DefaultObjectColor[1], DefaultObjectColor[2], DefaultObjectColor[3]};
}

float UCustomGameUserSettings::GetDefaultScale() const
{
	return DefaultObjectScale;
}
