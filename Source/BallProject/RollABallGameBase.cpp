// Fill out your copyright notice in the Description page of Project Settings.


#include "RollABallGameBase.h"
#include "Kismet/GameplayStatics.h"
#include <Blueprint/UserWidget.h>
#include "RollaBallWidget_UI.h"
#include "ItemBase.h"
#include "RollaBallWidget_UI.h"


void ARollABallGameBase::BeginPlay()
{

	TArray<AActor*> Items;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AItemBase::StaticClass(), Items);


	ItemsInLevel = Items.Num();

	if (GameWidgetClass)

	{

		GameWidget = Cast<URollaBallWidget_UI>(CreateWidget(GetWorld(), GameWidgetClass));

		//Adding the UI to the viewport (i.e. show UI when you start the game)

		


		if (GameWidget)
		{
			GameWidget->AddToViewport();
			UpdateItemText();

		}

	}


}



void ARollABallGameBase::UpdateItemText()
{

	GameWidget->SetItemText(ItemsCollected, ItemsInLevel);


}

void ARollABallGameBase::ItemCollected()
{

	//Increase number of items collected when you make contact with item

	ItemsCollected++;

	UpdateItemText();

	//FVector SoundLocation = ItemClass->GetActorLocation();


	if (ItemsInLevel == ItemsCollected)
	{

		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT("All done"));

		//Play victory sound here
		
		UGameplayStatics::PlaySound2D(GetWorld(), VictorySound, 1.0f);

		//Play victory animation

		GameWidget->UI_Animation();

	
		
	}

}

