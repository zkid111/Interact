// Copyright Epic Games, Inc. All Rights Reserved.

#include "InteractGameMode.h"
#include "InteractCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInteractGameMode::AInteractGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
