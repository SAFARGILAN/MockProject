// Fill out your copyright notice in the Description page of Project Settings.


#include"Components/SplineMeshComponent.h"
#include"Character/MainCharacter.h"
#include "Spine/SpineActor.h"


// Sets default values
ASpineActor::ASpineActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SplineComponent = CreateDefaultSubobject<USplineComponent>(FName("SplineComponent"));

	if (SplineComponent)
	{
		SetRootComponent(SplineComponent);
	}
}

void ASpineActor::OnConstruction(const FTransform& Transform)
{
	for (int SpineCount = 0; SpineCount < SplineComponent->GetNumberOfSplinePoints() - 1; ++SpineCount)
	{
		
		USplineMeshComponent* SpineMesh = NewObject<USplineMeshComponent>(this , USplineMeshComponent::StaticClass());
		SpineMesh->SetMobility(EComponentMobility::Movable);
		SpineMesh->CreationMethod = EComponentCreationMethod::UserConstructionScript;
		SpineMesh->RegisterComponentWithWorld(GetWorld());
		SpineMesh->AttachToComponent(SplineComponent, FAttachmentTransformRules::KeepRelativeTransform);
		const FVector StartPoint = SplineComponent->GetLocationAtSplinePoint(SpineCount, ESplineCoordinateSpace::Local);
		const FVector StartTangent = SplineComponent->GetTangentAtSplinePoint(SpineCount, ESplineCoordinateSpace::Local);
		const FVector EndPoint = SplineComponent->GetLocationAtSplinePoint(SpineCount, ESplineCoordinateSpace::Local);
		const FVector EndTangent = SplineComponent->GetTangentAtSplinePoint(SpineCount, ESplineCoordinateSpace::Local);
		SpineMesh->SetStartAndEnd(StartPoint, StartTangent, EndPoint, EndTangent , true);
	}
}

// Called when the game starts or when spawned
void ASpineActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

