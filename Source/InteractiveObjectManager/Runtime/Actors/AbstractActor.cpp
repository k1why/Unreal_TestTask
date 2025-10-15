// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractActor.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

#include "InteractiveObjectManager/Runtime/Settings/Logger.h"

// Sets default values
AAbstractActor::AAbstractActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
}

void AAbstractActor::SetActorData(const FActorData& InData)
{
	if (Data.Scale != InData.Scale) UpdateScale(InData.Scale);
	if (Data.Color != InData.Color) UpdateColor(InData.Color);
}

FActorData AAbstractActor::GetActorData() const
{
	return Data;
}

FSharedData AAbstractActor::ShareData_Implementation()
{
	return {GetName(), this};
}

void AAbstractActor::UpdateScale(const float InScale)
{
	Data.Scale = InScale;
	StaticMeshComponent->SetRelativeScale3D({Data.Scale, Data.Scale, Data.Scale});
}

void AAbstractActor::UpdateColor(const FLinearColor& InColor)
{
	Data.Color = InColor;

	if (Material)
	{
		Material->SetVectorParameterValue(FName("Color"), Data.Color);
	}
	else
	{
		UE_LOG(LogInteractiveManager, Warning, TEXT("[%s] Can't find Material Instance Dynamic : %s"), *this->GetName(), *StaticMeshComponent->GetMaterial(0)->GetName());
	}
}

void AAbstractActor::PostActorCreated()
{
	Super::PostActorCreated();

	if (auto BaseMaterial = StaticMeshComponent->GetMaterial(0))
	{
		Material = UMaterialInstanceDynamic::Create(StaticMeshComponent->GetMaterial(0),this);
		Material->SetFlags(RF_Transient);
		
		StaticMeshComponent->SetMaterial(0, Material);

		UE_LOG(LogInteractiveManager, Warning, TEXT("[%s] create Material name : %s"), *this->GetName(), *StaticMeshComponent->GetMaterial(0)->GetName());
	}
	else
	{
		UE_LOG(LogInteractiveManager, Error, TEXT("[%s] Impossible to find Material at 0"), *this->GetName());
	}
}
