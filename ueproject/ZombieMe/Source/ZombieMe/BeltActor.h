// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BeltActor.generated.h"

UCLASS()
class ZOMBIEME_API ABeltActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABeltActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* BeltStaticMeshComponent;

	UPROPERTY(EditAnywhere)
		float BeltMovingSpeed;

	UPROPERTY(EditAnywhere)
		float ResetDistance;    //How far it can move before it's placed at the beginning location

	FTransform StartTransform;
	float CurrentTranslation = 0;
};
