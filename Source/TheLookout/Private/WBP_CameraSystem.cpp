// Fill out your copyright notice in the Description page of Project Settings.


#include "WBP_CameraSystem.h"
#include "Components/Button.h"

void UWBP_CameraSystem::NativeConstruct()
{
	Super::NativeConstruct();
	
	//Adding the on clicked event for our button
	SwitchCamera_1->OnClicked.AddDynamic(this, &UWBP_CameraSystem::OnButtonClicked);
}

void UWBP_CameraSystem::OnButtonClicked()
{
	//Setting the text
	//TestText->SetText(FText::FromString("Testing the text"));
	
	
}
