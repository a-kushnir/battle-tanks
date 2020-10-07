// Andrew Kushnir

#include "BattleCity.h"
#include "DesignableUserWidget.h"

void UDesignableUserWidget::OnSynchronizeProperties_Implementation()
{
	// Override this event in Blueprint
}

void UDesignableUserWidget::SynchronizeProperties() {
	Super::SynchronizeProperties();
	OnSynchronizeProperties();
}