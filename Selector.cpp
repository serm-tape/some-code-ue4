// Fill out your copyright notice in the Description page of Project Settings.

#include "Selector.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


// Sets default values
ASelector::ASelector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASelector::BeginPlay()
{
	Super::BeginPlay();
	controller = GetWorld()->GetFirstPlayerController();
	CurrentActiveElement = nullptr;
}

// Called every frame
void ASelector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector pos, dir;
	controller->DeprojectMousePositionToWorld(pos, dir);

	FHitResult out;
	
	bool hit = GetWorld()->LineTraceSingleByChannel(
		out,
		pos + (dir * 30),
		pos + (dir * 1000),
		ECollisionChannel::ECC_GameTraceChannel2
	);

	if (hit) {
		AInteractableElement *a = Cast<AInteractableElement>(out.GetActor());
		if (a != CurrentActiveElement) {
			if (CurrentActiveElement != nullptr) {
				CurrentActiveElement->Deactivate();
			}
			a->Activate();
			CurrentActiveElement = a;
		}
	}
	else {
		if (CurrentActiveElement != nullptr) {
			CurrentActiveElement->Deactivate();
			CurrentActiveElement = nullptr;
		}
	}
}

