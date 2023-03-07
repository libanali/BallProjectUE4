// Fill out your copyright notice in the Description page of Project Settings.


#include "RollaBallWidget_UI.h"
#include "RollABallGameBase.h"
#include "Blueprint/UserWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "Components/TextBlock.h"


void URollaBallWidget_UI::NativeConstruct()

{
	Super::NativeConstruct();

}


void URollaBallWidget_UI::UI_Animation()

{
	// make victory text visible and play the animation here. After this, call it in the game mode cpp file

	Victory_Text->SetVisibility(ESlateVisibility::Visible);

	PlayAnimation(Victory_Animation, 0.0f, 1);

}

