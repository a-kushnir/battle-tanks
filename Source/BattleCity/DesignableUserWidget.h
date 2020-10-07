// Andrew Kushnir

#pragma once

#include "Blueprint/UserWidget.h"
#include "DesignableUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class BATTLECITY_API UDesignableUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	/**
	* This is called after a widget is constructed and properties are synchronized.
	* It can also be called by the editor to update modified state.
	* Override this event in blueprint to update the widget after a default property is modified.
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "User Interface")
		void OnSynchronizeProperties();

	virtual void SynchronizeProperties() override;
};
