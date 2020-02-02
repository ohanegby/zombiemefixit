// Fill out your copyright notice in the Description page of Project Settings.


#include "BeltActor.h"

// Sets default values
ABeltActor::ABeltActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BeltStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Conveyor Belt Mesh"));
}

// Called when the game starts or when spawned
void ABeltActor::BeginPlay()
{
	Super::BeginPlay();
	StartTransform = GetActorTransform();
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
	FVector StartTranslation = StartTransform.GetTranslation();
	FTransform NewTransform = StartTransform;
	NewTransform.SetTranslation(FVector(StartTranslation.X + CurrentTranslation, StartTranslation.Y, StartTranslation.Z));
	SetActorTransform(NewTransform);

}

