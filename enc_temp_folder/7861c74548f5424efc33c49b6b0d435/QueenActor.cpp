// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "QueenActor.h"


// Sets default values
AQueenActor::AQueenActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StartPosition.x = 0;
	StartPosition.y = 0;

}

// Called when the game starts or when spawned
void AQueenActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQueenActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
//вывод на экран
void AQueenActor::SPrintResult()
{
	
}
//очистка положения на доске
void AQueenActor::ClearDesc()
{
	for (int i = 0; i< MAX_SLOT*MAX_SLOT; i++)
	{
		iDesc8x8[i] = 0;
	}

	StartPosition.x++;

	if (StartPosition.x>=MAX_SLOT)
	{
		StartPosition.x = 0;
		StartPosition.y++;
	}

	if (StartPosition.y >= MAX_SLOT)
	{
		StartPosition.x = 0;
		StartPosition.y = 0;
	}
}


