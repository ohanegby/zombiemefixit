// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombie.h"
#include "Engine/DecalActor.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Components/DecalComponent.h"
#include "Components/BoxComponent.h"
//#include "zombieMeProjectile.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "WeaponCollision.h"

// Sets default values
AZombie::AZombie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());

	LeftShoulderCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("LeftShoulderCollision"));
	LeftShoulderCollision->SetupAttachment(Mesh, FName("LeftShoulderHitPoint"));


	RightShoulderCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("RightShoulderCollision"));
	RightShoulderCollision->SetupAttachment(Mesh, FName("RightShoulderHitPoint"));

	LeftLegCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("LeftLegCollision"));
	LeftLegCollision->SetupAttachment(Mesh, FName("LeftLegHitPoint"));

	RightLegCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("RightLegCollision"));
	RightLegCollision->SetupAttachment(Mesh, FName("RightLegHitPoint"));

	NeckCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("NeckCollision"));
	NeckCollision->SetupAttachment(Mesh, FName("NeckHitPoint"));

	counter = 5;

}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();

	LeftShoulderCollision->OnComponentBeginOverlap.AddDynamic(this, &AZombie::HitTargetCollisionOnOverlapBegin);
	RightShoulderCollision->OnComponentBeginOverlap.AddDynamic(this, &AZombie::HitTargetCollisionOnOverlapBegin);
	LeftLegCollision->OnComponentBeginOverlap.AddDynamic(this, &AZombie::HitTargetCollisionOnOverlapBegin);
	RightLegCollision->OnComponentBeginOverlap.AddDynamic(this, &AZombie::HitTargetCollisionOnOverlapBegin);
	NeckCollision->OnComponentBeginOverlap.AddDynamic(this, &AZombie::HitTargetCollisionOnOverlapBegin);

	SetHitPointCollision(LeftShoulderCollision);
	SetHitPointCollision(RightShoulderCollision);
	SetHitPointCollision(LeftLegCollision);
	SetHitPointCollision(RightLegCollision);
	SetHitPointCollision(NeckCollision);

	//Constraint->SetConstrainedComponents(ConstraintBox, TEXT("ConstraintBox"), GetMesh(), TEXT("Head"));

	UE_LOG(LogTemp, Warning, TEXT("zomebie created"));
}

void AZombie::SetHitPointCollision(UBoxComponent* Component)
{
	Component->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Component->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	Component->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

}


void AZombie::HitTargetCollisionOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("zomebie hitted"));

	if (OtherActor)
	{
		
		AWeaponCollision* Weapon = Cast<AWeaponCollision>(OtherActor);
		if (Weapon && Weapon->bEnabled)
		{
			// We assume that the collsion volum will has at least one child which is the decal
			USceneComponent* DecalComponent = OverlappedComponent->GetChildComponent(0);
			if (DecalComponent)
			{
				UE_LOG(LogTemp, Warning, TEXT("zomebie point hidden"));

				//DecalComponent->SetHiddenInGame(true);
				DecalComponent->DestroyComponent(true);
				counter--;
			}
		}
	}
}