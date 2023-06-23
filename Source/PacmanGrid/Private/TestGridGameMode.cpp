// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGridGameMode.h"

ATestGridGameMode::ATestGridGameMode()
{

}


void ATestGridGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	// con questa posizione la tile di coordinate griglia (0,0) ha come
	// coordinate nello spazio dello spigolo inferiore sinistro (0,0) 
	// 
	// es. coordinate nello spazio della tile di coordinate di griglia (0, 0) 
	// 
	// (100,0) -------------- (100,100)
    //         |            |
	//		   |            |
	//         |  (50, 50)  |
	//         |            |
	//         |            |
	//  (0,0)  -------------- (0, 100)
	//

	FVector GridPos(50.0f, 50.0f, 0.0f);
	// N.B. tutte le funzioni andrebbero normalizzate se la posizione
	// della griglia non fosse pi� questa ma una qualsiasi nello spazio tridimensionale
	if (GridGeneratorClass != nullptr)
	{
		// spawn della griglia
		GField = GetWorld()->SpawnActor<AGridGenerator>(GridGeneratorClass, GridPos, FRotationMatrix::MakeFromX(FVector(0, 0, 0)).Rotator());
	};

	BlinkyPawn = GetWorld()->SpawnActor<ABlinky>(BlinkyClass, FVector((100 * 17) + 50, (100 * 12) + 50, 5.0f), FRotator(0, 0, 0));
	InkyPawn = GetWorld()->SpawnActor<AInky>(InkyClass, FVector((100 * 17) + 50, (100 * 13) + 50, 5.0f), FRotator(0, 0, 0));
	PinkyPawn = GetWorld()->SpawnActor<APinky>(PinkyClass, FVector((100 * 17) + 50, (100 * 14) + 50, 5.0f), FRotator(0, 0, 0));
	ClydePawn = GetWorld()->SpawnActor<AClyde>(ClydeClass, FVector((100 * 17) + 50, (100 * 15) + 50, 5.0f), FRotator(0, 0, 0));
}