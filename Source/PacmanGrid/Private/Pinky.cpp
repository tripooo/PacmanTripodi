// Fill out your copyright notice in the Description page of Project Settings.


#include "Pinky.h"

AGridBaseNode* APinky::GetPlayerRelativeTarget()
{
	return Super::GetPlayerRelativeTarget();
}

APinky::APinky()
{
	CurrentGridCoords = FVector2D(17, 14);
}



