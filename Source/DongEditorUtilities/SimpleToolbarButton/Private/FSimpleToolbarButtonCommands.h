// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Framework/Commands/Commands.h"
/**
 * 
 */
class DONGEDITORUTILITIES_API FSimpleToolbarButtonCommands : public TCommands<FSimpleToolbarButtonCommands>
{
public:
	FSimpleToolbarButtonCommands()
		: TCommands<FSimpleToolbarButtonCommands>(TEXT("ExampleToolbarButton"), NSLOCTEXT("Contexts", "ExampleToolbarButton", "ExampleToolbarButton Plugin"), NAME_None, FSimpleToolbarButtonCommands::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
