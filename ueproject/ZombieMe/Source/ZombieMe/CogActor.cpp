// Fill out your copyright notice in the Description page of Project Settings.


#include "CogActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACogActor::ACogActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DummyComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy Scene Component"));
	SetRootComponent(DummyComponent);
	CogMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cog Mesh Component"));
	CogMeshComponent->AttachTo(DummyComponent);
}

// Called when the game starts or when spawned
void ACogActor::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ACogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotatePitch.Pitch += DeltaTime * RotationSpeed;
	CogMeshComponent->SetRelativeRotation(RotatePitch);
}

