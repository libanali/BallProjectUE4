// Fill out your copyright notice in the Description page of Project Settings.


#include "BallPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABallPlayer::ABallPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	//Create Components - Before this step, they won't exist on our Actor. They've only been defined.
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	//Set the Root Component to be our Mesh.
	RootComponent = Mesh;


	//Attach the SpringArm to the mesh, spring will now follow the mesh transform.
	SpringArm->SetupAttachment(Mesh);


	//Attach the Camera to the SpringArm, Camera will now follow the SpringArm transform.
	Camera->SetupAttachment(SpringArm);


	//Set physics to true
	Mesh->SetSimulatePhysics(true);


	Mesh->OnComponentHit.AddDynamic(this, &ABallPlayer::OnHit);

}

// Called when the game starts or when spawned
void ABallPlayer::BeginPlay()
{
	Super::BeginPlay();

	//Account for mass in MoveForce


	MoveForce *= Mesh->GetMass();

	JumpImpulse *= Mesh->GetMass();

	
}







// Called every frame
void ABallPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABallPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Setting up Custom Input Binding

	InputComponent->BindAxis("MoveForward", this, &ABallPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABallPlayer::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ABallPlayer::Jump);


}

void ABallPlayer::MoveRight(float Value)
{

	//Make Pawn move to the right by adding force to the right vector

	const FVector Right = Camera->GetRightVector() * MoveForce * Value;
	Mesh->AddForce(Right);


}

void ABallPlayer::MoveForward(float Value)
{

	//Make pawn move to forward by adding force to the forward vector

	const FVector Forward = Camera->GetForwardVector() * MoveForce * Value;
	Mesh->AddForce(Forward);

}

void ABallPlayer::Jump()
{
	//Cap the number of jumps we can make


	if (JumpCount >= MaxJumpCount)
	{
		return;
	}


	//Make pawn jump (applying impulse to Z axis)
	Mesh->AddImpulse(FVector(0, 0, JumpImpulse));


	//Track how many times we've jumped

	JumpCount++;


	//Camera Shake


}

void ABallPlayer::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//Get direction we hit the surface on the Z axis

	const float HitDirection = Hit.Normal.Z;


	//If it's more than 0, than we've hit something below us. 1 is flat, anything between is a slope.

	if (HitDirection > 0)
	{
		JumpCount = 0;
	}


}

