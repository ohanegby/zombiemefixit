// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CogActor.generated.h"

UCLASS()
class ZOMBIEME_API ACogActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACogActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DummyComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CogMeshComponent;

	UPROPERTY(EditAnywhere)
	float RotationSpeed;

	FRotator RotatePitch;
};
