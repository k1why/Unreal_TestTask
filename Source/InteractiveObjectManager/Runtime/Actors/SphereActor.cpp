// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereActor.h"

ASphereActor::ASphereActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BaseMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	StaticMeshComponent->SetStaticMesh(BaseMeshAsset.Object);
}
