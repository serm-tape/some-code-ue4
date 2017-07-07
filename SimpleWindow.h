// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SimpleWindow.generated.h"

/**
 * 
 */
UCLASS()
class POC3_API USimpleWindow : public UUserWidget
{
	GENERATED_BODY()
	
	public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Simple Window Widget")
		FString Title;
	
		UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Simple Window Widget")
		FString Content;
};
