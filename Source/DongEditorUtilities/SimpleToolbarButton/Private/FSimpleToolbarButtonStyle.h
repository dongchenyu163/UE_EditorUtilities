// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"

class FSimpleToolbarButtonStyle
{
public:

	void Initialize(FName InStyleSetName, FName InPropertyName, FString InIconFileName, FString InPluginRoot);

	void Shutdown();

	/** reloads textures used by slate renderer */
	void ReloadTextures();

	/** @return The Slate style set for the Shooter game */
	const ISlateStyle& Get();

	FName GetStyleSetName();

private:

	TSharedRef< class FSlateStyleSet > Create();

private:

	TSharedPtr< class FSlateStyleSet > StyleInstance;

	FName PropertyName;
	FName StyleSetName;
	FString IconFileName;
	FString PluginRoot;
};