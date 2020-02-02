// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponCollision.h"
#include "Components/BoxComponent.h"

// Sets default values
AWeaponCollision::AWeaponCollision()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DamageCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageCollision"));
	DamageCollision->SetupAttachment(GetRootComponent());

	bEnabled = true;
}

// Called when the game starts or when spawned
void AWeaponCollision::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponCollision::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

