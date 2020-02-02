// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponCollision.generated.h"

UCLASS()
class ZOMBIEME_API AWeaponCollision : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponCollision();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
	class UBoxComponent* DamageCollision;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	bool bEnabled;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void CollisionEnable() { bEnabled = true; }

	UFUNCTION(BlueprintCallable)
	void CollisionDisable() { bEnabled = false; }

};
