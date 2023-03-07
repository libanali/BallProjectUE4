// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCameraShake.h"

UMyCameraShake::UMyCameraShake()

{

	//Duration of shake 
	OscillationDuration = 0.25f;
	OscillationBlendInTime = 0.05f;
	OscillationBlendOutTime = 0.05f;





	//Direction of camera shake 



	//X Axis

	RotOscillation.Roll.Amplitude = FMath::RandRange(3.5f, 5.0f);
	RotOscillation.Roll.Frequency = FMath::RandRange(3.5f, 5.0f);



	//Y Axis
	RotOscillation.Pitch.Amplitude = FMath::RandRange(3.5f, 5.0f);
	RotOscillation.Pitch.Frequency = FMath::RandRange(3.5f, 5.0f);



	//Z Axis
	RotOscillation.Yaw.Amplitude = FMath::RandRange(3.5f, 5.0f);
	RotOscillation.Yaw.Frequency = FMath::RandRange(3.5f, 5.0f);



}
