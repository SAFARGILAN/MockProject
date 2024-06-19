
// Fill out your copyright notice in the Description page of Project Settings.




#include "Character/MainCharacter.h"
#include"MotionControllerComponent.h"
#include"Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Weapon/Weapon.h"



// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LeftController = CreateDefaultSubobject<UMotionControllerComponent>(FName("LeftController"));
	LeftController->SetupAttachment(GetRootComponent());
	Left = CreateDefaultSubobject<USkeletalMeshComponent>(FName("LeftMesh"));
	Left->SetupAttachment(LeftController);
	RightController = CreateDefaultSubobject<UMotionControllerComponent>(FName("RightController"));
	RightController->SetupAttachment(GetRootComponent());
	Right = CreateDefaultSubobject<USkeletalMeshComponent>(FName("RightMesh"));
	Right->SetupAttachment(RightController);
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(FName("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>(FName("Camera"));
	Camera->SetupAttachment(CameraBoom);
	
	
	
	
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (World && WeaponClass)
	{
		AWeapon* DefaultWeapon = World->SpawnActor<AWeapon>(WeaponClass);
		FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
		DefaultWeapon->AttachToComponent(Right, TransformRules , FName("RightHandSocket"));
	}
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddMovementInput(this->GetActorForwardVector(), 1.0f);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

