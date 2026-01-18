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
	SwitchCameras->OnClicked.AddDynamic(this, &UWBP_CameraSystem::OnSwitchCameraButtonClicked);
	BackButton->OnClicked.AddDynamic(this, &UWBP_CameraSystem::OnBackButtonClicked);
	
	//Getting actor of class
	CameraSwitcher = Cast<ACameraSwitcher>
	(
		UGameplayStatics::GetActorOfClass(
			GetWorld(),
			ACameraSwitcher::StaticClass()
		)
	);
	
	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
}

// Intializing the OnButtonClicked event
void UWBP_CameraSystem::OnSwitchCameraButtonClicked()
{
	//Setting the text
	//TestText->SetText(FText::FromString("Testing the text"));
	
	// Incrementing so the camera switching to the next
	CameraID++;
	
	//Checking if CameraSwitcher is correctly initialized 
	if (CameraSwitcher)
	{
		if (CameraID == 1)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, TEXT("1"));
			
			//Set Main Camera to active
			CameraSwitcher->ActivateMainCamera();
		
			GetOwningPlayer()->SetViewTargetWithBlend(CameraSwitcher, 0.5f);
		}
		
		if (CameraID == 2)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, TEXT("2"));
			
			CameraSwitcher->ActivateSecondCamera();
		
			GetOwningPlayer()->SetViewTargetWithBlend(CameraSwitcher, 0.5f);
			
			//Resetting CameraID to 0 so it switches back the first camera
			CameraID = 0;
		}
		
		//On screen debug
		//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, TEXT("Is it working?"));
	}

}


void UWBP_CameraSystem::OnBackButtonClicked()
{
	//Setting the input mode to game only
	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->SetShowMouseCursor(false);
	
	//Removing the widget from the screen
	RemoveFromParent();
}
