#include "FSimpleToolbarButtonStyle.h"// Copyright Epic Games, Inc. All Rights Reserved.

#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

// TSharedPtr<FSlateStyleSet> FSimpleToolbarButtonStyle::StyleInstance = nullptr;

void FSimpleToolbarButtonStyle::Initialize(FName InStyleSetName, FName InPropertyName, FString InIconFileName, FString InPluginRoot)
{
	PropertyName = InPropertyName;
	StyleSetName = InStyleSetName;
	IconFileName = InIconFileName;
	PluginRoot = InPluginRoot;
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FSimpleToolbarButtonStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FSimpleToolbarButtonStyle::GetStyleSetName()
{
	// static FName StyleSetName(TEXT("ExampleToolbarButtonStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FSimpleToolbarButtonStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet(StyleSetName));
	Style->SetContentRoot(PluginRoot / TEXT("Resources"));

	// Style->Set("ExampleToolbarButton.PluginAction", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));
	Style->Set(PropertyName, new IMAGE_BRUSH_SVG(*IconFileName, Icon20x20));
	return Style;
}

void FSimpleToolbarButtonStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FSimpleToolbarButtonStyle::Get()
{
	return *StyleInstance;
}
