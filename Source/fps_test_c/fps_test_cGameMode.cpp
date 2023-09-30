// Copyright Epic Games, Inc. All Rights Reserved.

#include "fps_test_cGameMode.h"
#include "fps_test_cCharacter.h"
#include "UObject/ConstructorHelpers.h"

Afps_test_cGameMode::Afps_test_cGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
