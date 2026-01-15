// Fill out your copyright notice in the Description page of Project Settings.


#include "WBP_CameraSystem.h"
#include "Components/Button.h"
#include "CameraSwitcher.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

void UWBP_CameraSystem::NativeConstruct()
{
	Super::NativeConstruct();
	
	//Adding the on clicked event for our button
	SwitchCameras->OnClicked.AddDynamic(this, &UWBP_CameraSystem::OnButtonClicked);
	
	//Getting actor of class
	CameraSwitcher = Cast<ACameraSwitcher>
	(
		UGameplayStatics::GetActorOfClass(
			GetWorld(),
			ACameraSwitcher::StaticClass()
		)
	);
}

// Intializing the OnButtonClicked event
void UWBP_CameraSystem::OnButtonClicked()
{
	//Setting the text
	//TestText->SetText(FText::FromString("Testing the text"));
	
	//Checking if CameraSwitcher is correctly initialized 
	if (CameraSwitcher)
	{
		//On screen debug
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, TEXT("Is it working?"));
		
		//Set cameras to active
		CameraSwitcher->ActivateMainCamera();
		
		GetOwningPlayer()->SetViewTargetWithBlend(CameraSwitcher, 0.1f);
	}

}
