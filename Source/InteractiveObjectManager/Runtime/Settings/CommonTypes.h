#pragma once

#include "CoreMinimal.h"
#include "CommonTypes.generated.h"


UENUM(BlueprintType)
enum class ESpawnPrimitiveType : uint8
{
	CUBE   = 0 UMETA(DisplayName = "CUBE"),
	SPHERE = 1 UMETA(DisplayName = "SPHERE"),
};

USTRUCT(BlueprintType, Blueprintable)
struct FActorData
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	float Scale;
	
	UPROPERTY(BlueprintReadWrite)
	FLinearColor Color;
	
	UPROPERTY(BlueprintReadWrite)
	ESpawnPrimitiveType Type;
};