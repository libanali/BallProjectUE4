 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RollaBallWidget_UI.generated.h"

/**
 * 
 */
UCLASS()
class BALLPROJECT_API URollaBallWidget_UI : public UUserWidget
{
	GENERATED_BODY()


public:


	UFUNCTION(BlueprintImplementableEvent)
	void SetItemText(int32 ItemsCollected, int32 ItemsInLevel);
	

	UPROPERTY(Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* Victory_Animation;


	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* Victory_Text;


	void NativeConstruct() override;

	void UI_Animation();
};
