// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon/Weapon.h"
#include"Components/StaticMeshComponent.h"
#include"MotionControllerComponent.h"
#include"Components/BoxComponent.h"
#include"Character/MainCharacter.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));

	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisonBox"));
	WeaponCollisionBox->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	//FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
	//WeaponMesh->SetupAttachment(CharacterRef->RightController, FName("WeaponSocket"));
	 
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

