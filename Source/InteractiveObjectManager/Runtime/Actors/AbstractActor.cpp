// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractActor.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialExpressionConstant3Vector.h"

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
	Data = InData;
	UpdateActor();
}

FSharedData AAbstractActor::ShareData_Implementation()
{
	return {GetName(), this};
}

void AAbstractActor::UpdateActor()
{
	StaticMeshComponent->SetRelativeScale3D({Data.Scale, Data.Scale, Data.Scale});
}
