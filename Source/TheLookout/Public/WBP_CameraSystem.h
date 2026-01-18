// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "CameraSwitcher.h"
#include "WBP_CameraSystem.generated.h"

/**
 * 
 */
UCLASS()
class THELOOKOUT_API UWBP_CameraSystem : public UUserWidget
{
	GENERATED_BODY()
	
private:
	
	int CameraID = 0;
	
	APlayerController* PlayerController;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* BackButton;
	
	//Adding widget components
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* SwitchCameras;
	
	UPROPERTY(BlueprintreadWrite)
	ACameraSwitcher* CameraSwitcher;
	
	//UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	//UTextBlock* TestText;
	
	virtual void NativeConstruct() override;
	
	//Creating functions
	UFUNCTION()
	void OnSwitchCameraButtonClicked();
	
	UFUNCTION()
	void OnBackButtonClicked();
	
};
