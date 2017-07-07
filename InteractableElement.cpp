// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableElement.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "EngineUtils.h"

// Sets default values
AInteractableElement::AInteractableElement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
	RootMesh->SetCollisionProfileName(TEXT("InteractableItem"));
	RootMesh->bRenderCustomDepth = true;
	RootMesh->CustomDepthStencilValue = 0;
	RootComponent = RootMesh;

	PostProcessComponent = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcess"));
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/PP_OutlineColored'"));
	if (Material.Object) {
		PostProcessComponent->AddOrUpdateBlendable(Material.Object);
		PostProcessComponent->SetupAttachment(RootComponent);
	}
}

// Called when the game starts or when spawned
void AInteractableElement::BeginPlay()
{
	Super::BeginPlay();
	isActive = false;

	//TODO: find popup window here
}

// Called every frame
void AInteractableElement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractableElement::Activate() {
	if (!isActive) {
		UE_LOG(LogTemp, Warning, TEXT("Activated"));
		RootMesh->CustomDepthStencilValue = 252;
		//TODO: change content on windows and display
		MarkComponentsRenderStateDirty();
		isActive = true;
	}
}

void AInteractableElement::Deactivate() {
	if (isActive) {
		UE_LOG(LogTemp, Warning, TEXT("Deactivate"));
		RootMesh->CustomDepthStencilValue = 0;
		//TODO: hide window
		MarkComponentsRenderStateDirty();
		isActive = false;
	}
}
