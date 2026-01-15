// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "WBP_CameraSystem.generated.h"

/**
 * 
 */
UCLASS()
class THELOOKOUT_API UWBP_CameraSystem : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	//Adding button 
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* SwitchCamera_1;
	
	//UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	//UTextBlock* TestText;
	
	virtual void NativeConstruct() override;
	
	UFUNCTION()
	void OnButtonClicked();
	
};
