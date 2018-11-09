// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReport.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	AActor * Owner = GetOwner();
	FString ObjectName = Owner != nullptr ? GetOwner()->GetName() : "N/A";
	UE_LOG(LogTemp, Warning, TEXT("PositionReport reporting for duty on %s!"), *ObjectName);
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
