// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class UMotionControllerComponent;
class UCameraComponent;
class USpringArmComponent;
class USceneComponent;


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
	

	
	





public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		UMotionControllerComponent* LeftController;

	UPROPERTY(EditAnywhere , BlueprintReadOnly)
		UMotionControllerComponent* RightController;

	UPROPERTY(EditAnywhere , BlueprintReadOnly)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
		USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AWeapon> WeaponClass;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* Right;

	UPROPERTY(EditAnywhere , BlueprintReadOnly )
		USkeletalMeshComponent* Left;

	
	

};
