// Fill out your copyright notice in the Description page of Project Settings.


#include "BeltActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABeltActor::ABeltActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DummyComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy Scene Component"));
	SetRootComponent(DummyComponent);
	BeltStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Conveyor Belt Mesh"));
	BeltStaticMeshComponent->AttachTo(DummyComponent);
}

// Called when the game starts or when spawned
void ABeltActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABeltActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
	CurrentTranslation += DeltaTime * BeltMovingSpeed;

	if (CurrentTranslation > ResetDistance)
	{
		CurrentTranslation = 0;
	}

	BeltStaticMeshComponent->SetRelativeLocation(FVector(CurrentTranslation, 0, 0));
}

