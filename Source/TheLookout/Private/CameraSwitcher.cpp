// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraSwitcher.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACameraSwitcher::ACameraSwitcher()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Intializing the camera components
	MainCamera = CreateDefaultSubobject<UCameraComponent>(FName("MainCamera"));
	
	MainCamera->SetupAttachment(RootComponent);
	
	SecondCamera = CreateDefaultSubobject<UCameraComponent>(FName("SecondCamera"));
	
	SecondCamera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACameraSwitcher::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACameraSwitcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACameraSwitcher::ActivateMainCamera()
{
	//Optimising by setting active camera not being used to unactive
	MainCamera->SetActive(true);
	SecondCamera->SetActive(false);
}

void ACameraSwitcher::ActivateSecondCamera()
{
	//Optimising by setting active camera not being used to unactive
	MainCamera->SetActive(false);
	SecondCamera->SetActive(true);
}

