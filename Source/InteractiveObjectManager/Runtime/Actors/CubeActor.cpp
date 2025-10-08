// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeActor.h"

ACubeActor::ACubeActor()
	: Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BaseMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	StaticMeshComponent->SetStaticMesh(BaseMeshAsset.Object);
}
