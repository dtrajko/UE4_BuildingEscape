// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsHandleComponent.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// Setup attached (assumed) physics handle component
	void FindPhysicsHandleComponent();
	// Setup attached (assumed) input component
	void SetupInputComponent();
	// Return hit for first physics body in reach
	FHitResult GetFirstPhysicsBodyInReach() const;

	FVector GetReachLineStart() const;
	FVector GetReachLineEnd() const;

	// Ray-case and grab what's in reach
	void Grab();
	// Called when grab is released
	void Release();

private:
	// How far ahead of the player can we reach in centimeters
	float Reach = 100.0f;
	UPhysicsHandleComponent * PhysicsHandle = nullptr;
	UInputComponent * InputComponent = nullptr;

};
