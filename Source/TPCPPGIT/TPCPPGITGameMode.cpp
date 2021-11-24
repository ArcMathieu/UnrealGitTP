// Copyright Epic Games, Inc. All Rights Reserved.

#include "TPCPPGITGameMode.h"
#include "TPCPPGITCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATPCPPGITGameMode::ATPCPPGITGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ATPCPPGITGameMode::Respawn(AController* currentController)
{
	FVector StartLocation = FVector(-800, 350, 230);
	if (APawn* Pawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, StartLocation, FRotator::ZeroRotator))
	{
		currentController->Possess(Pawn);
	}
	
}
