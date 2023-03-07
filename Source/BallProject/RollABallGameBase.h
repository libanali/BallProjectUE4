
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RollABallGameBase.generated.h"

class URollaBallWidget_UI;
class USoundBase;
class AItemBase;

/**
 * 
 */
UCLASS()
class BALLPROJECT_API ARollABallGameBase : public AGameModeBase
{
	GENERATED_BODY()



protected:

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//int32 ItemsCollected = 0;

//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//int32 ItemsInLevel = 0;


	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<class UUserWidget> GameWidgetClass;

	



	UPROPERTY()
		URollaBallWidget_UI* GameWidget;

	

	 
	//UPROPERTY(EditAnywhere)
	//	USoundBase* VictorySound;

	UPROPERTY()
		AItemBase* ItemClass;

 


	
	virtual void BeginPlay() override;

	void UpdateItemText();


public:

	void ItemCollected();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USoundBase* VictorySound;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
int32 ItemsCollected = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ItemsInLevel = 0;


};
