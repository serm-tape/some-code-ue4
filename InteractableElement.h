// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SimpleWindow.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PostProcessComponent.h"
#include "InteractableElement.generated.h"

UCLASS()
class POC3_API AInteractableElement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableElement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TScriptInterface<IBlendableInterface> FocusBlend;

	UPROPERTY(EditAnywhere)
	UPostProcessComponent *PostProcessComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *RootMesh;

	UPROPERTY(EditAnyWhere)
	USimpleWindow *InfoWindow;

	bool isActive;
	virtual void Activate();
	virtual void Deactivate();
};
