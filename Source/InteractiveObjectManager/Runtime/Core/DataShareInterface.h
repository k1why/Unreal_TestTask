#pragma once
#include "CoreMinimal.h"
#include "DataShareInterface.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FSharedData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString Name;

	UPROPERTY(BlueprintReadWrite)
	AActor* Actor;
};

UINTERFACE(MinimalAPI)
class UDataShareInterface : public UInterface
{
	GENERATED_BODY()
};

class INTERACTIVEOBJECTMANAGER_API IDataShareInterface
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Data Transfer")
	FSharedData ShareData();
};
