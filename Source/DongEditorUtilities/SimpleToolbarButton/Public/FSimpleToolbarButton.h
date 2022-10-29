#pragma once

class DONGEDITORUTILITIES_API FToolbarButtonCreationParams
{
	// Menu base area
	FString ButtonName;
	FName LoadPointName;
	TArray<FName> SubSectionList;

	// Style area
};

class DONGEDITORUTILITIES_API FSimpleToolbarButton
{
public:
	FSimpleToolbarButton() {}
	FSimpleToolbarButton(const TArray<FToolbarButtonCreationParams>& InButtonCreationParamList) { ButtonCreationParamList = InButtonCreationParamList; }
	virtual ~FSimpleToolbarButton() {}
	
	/**
	 * @brief Should called at ::ShutdownModule() function.
	 */
	virtual void InitButton();

	/**
	 * @brief Should called at ::ShutdownModule() function.
	 */
	virtual void UnInitButton();

	virtual void RegisterMenus_Internal();

	virtual void OnButtonClicked() = 0; 


public:
	TArray<FToolbarButtonCreationParams> ButtonCreationParamList;
	// TArray<FToolbarButtonCreationParams>& InButtonCreationParamList;
};
