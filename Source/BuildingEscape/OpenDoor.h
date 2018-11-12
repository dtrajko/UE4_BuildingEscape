// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/TriggerVolume.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// returns total mass in kg
	float GetTotalMassOfActorsOnPlate();

private:
	UPROPERTY(VisibleAnywhere)
	float OpenAngle = -120.0f;

	float ClosedAngle = -180.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume * PressurePlate;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.7f;

	UPROPERTY(EditAnywhere)
	float OpenDoorTriggerMass = 30.0f;

	float LastDoorOpenTime;

	// Find the owning actor
	AActor * Owner;

};
