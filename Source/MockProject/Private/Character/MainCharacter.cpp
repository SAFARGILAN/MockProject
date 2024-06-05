// Fill out your copyright notice in the Description page of Project Settings.




#include "Character/MainCharacter.h"
#include"MotionControllerComponent.h"
#include"Components/SkeletalMeshComponent.h"
#include"Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"



// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VROrigin = CreateDefaultSubobject<USceneComponent>(TEXT("VROrigin"));
	

	LeftController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Left Controller"));
	RightController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Right Controller"));

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(RightController, FName("GripPoint"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 150.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("View Camera"));
	Camera->SetupAttachment(CameraBoom);
	
	
	
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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

