// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "BallPlayer.h"
#include "RollABallGameBase.h"
#include "Kismet/GameplayStatics.h"
#include "ActiveSound.h"


// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	RootComponent = Mesh;

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OverlapBegin);

}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();

	
	
}

void AItemBase::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{


	if (Cast<ABallPlayer>(OtherActor) != nullptr)
	{
		Collected();

		UGameplayStatics::PlaySoundAtLocation(GetWorld(), CollectSound, GetActorLocation());
		
	}




}

void AItemBase::Collected_Implementation()
{


	ARollABallGameBase* GameMode = Cast<ARollABallGameBase>(GetWorld()->GetAuthGameMode());


	if (GameMode)
	{

		GameMode->ItemCollected();

	}


}





