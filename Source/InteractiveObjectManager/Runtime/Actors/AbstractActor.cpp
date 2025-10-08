// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractActor.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialExpressionConstant3Vector.h"
#include "Materials/MaterialParameterCollectionInstance.h"

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
	if (UMaterialParameterCollectionInstance* PCI = GetWorld()->GetParameterCollectionInstance(MaterialParamCollection))
	{
		bool Found = PCI->SetVectorParameterValue(FName("Color"), Data.Color);
	}
}
