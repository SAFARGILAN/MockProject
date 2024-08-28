// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"


class UStaticMeshComponent;
class AMainCharacter;
class UBoxComponent;
class USceneComponent;

UCLASS()
class MOCKPROJECT_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TObjectPtr<UStaticMeshComponent> WeaponMesh;

	AMainCharacter* CharacterRef;

	UPROPERTY(BlueprintReadOnly)
		USceneComponent* BoxTraceEnd;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	//TObjectPtr<UBoxComponent> WeaponCollisionBox;

	



	//UFUNCTION(BlueprintCallable)
	//void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceStart;

	
	UPROPERTY(VisibleAnywhere)
	TSubclassOf<UInterface> GetHit;
	
};
