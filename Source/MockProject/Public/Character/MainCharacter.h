// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class UMotionControllerComponent;
class USceneComponent;
class USkeletalMeshComponent;

UCLASS()
class MOCKPROJECT_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		UMotionControllerComponent* LeftController;

	UPROPERTY(EditAnywhere)
		UMotionControllerComponent* RightController;

	USceneComponent* VROrigin;

	UPROPERTY(EditAnywhere)
		TObjectPtr<USkeletalMeshComponent> Weapon;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
