// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "QueenActor.h"
#include "Engine.h"


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
	SPrintResult();
}

// Called every frame
void AQueenActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
//вывод на экран
void AQueenActor::SPrintResult()
{
	///////////////////
	iPosition pos;
	pos.x = 2;
	pos.y = 3;
	HorisontFill(pos);
	///////////////////
	
	for (int32 k = 64; k<=0; k-=8)
	{
		
			GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("%d;%d;%d;%d;%d;%d;%d;%d"), 
				iDesc8x8[k-7],
				iDesc8x8[k-6], 
				iDesc8x8[k-5], 
				iDesc8x8[k-4], 
				iDesc8x8[k-3], 
				iDesc8x8[k-2], 
				iDesc8x8[k-1], 
				iDesc8x8[k]));
		
	}
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

//Заполнение полей по горизонтале
void AQueenActor::HorisontFill(iPosition AddPosition)
{
	int32 IndexSlot = AddPosition.x*8+AddPosition.y-AddPosition.x-1;
	for (int32 x = 0; x<MAX_SLOT; x++)
	{
		iDesc8x8[IndexSlot + x] = 1;
	}
}
//Заполнение полей по вертикале
void AQueenActor::VerticalFill(iPosition AddPosition)
{
	int32 IndexSlot = AddPosition.x*8+AddPosition.y - AddPosition.y-1;
	for (int32 y = 0; y<MAX_SLOT; y+=8)
	{
		iDesc8x8[IndexSlot + y] = 1;
	}
}
//Заполнение полей по диоганалям
void AQueenActor::DioganalFill(iPosition AddPosition)
{
}
/*
 * 1  2  3  4  5  6  7  8
 * 9 10 11 12 13 14 15 16
 * 17 18 19 
 */