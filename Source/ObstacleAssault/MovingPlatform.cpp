// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//Move platform forwards
		// Get current Location
	FVector CurrentLocation = GetActorLocation();
		// add Vector to location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		// Set Location
	SetActorLocation(CurrentLocation);
	// Send Platform back if we've gone too far
		//Check how far we've moved
	float DistanceMoved = FVector::Dist(StartLocation, GetActorLocation());
	// reverse direction
	if (DistanceMoved > MoveDistance)
	{
		// Prevent drifting
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		
		PlatformVelocity = -(PlatformVelocity);
	}
}

