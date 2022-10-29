// Fill out your copyright notice in the Description page of Project Settings.


#include "FSimpleToolbarButtonCommands.h"

#define LOCTEXT_NAMESPACE "FExampleToolbarButtonModule"

void FSimpleToolbarButtonCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "ExampleToolbarButton", "Execute ExampleToolbarButton action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
