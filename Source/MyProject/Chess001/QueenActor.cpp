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
	pos.x = 4;
	pos.y = 4;
	HorisontFill(pos);
	VerticalFill(pos);
	DioganalFill(pos);
	///////////////////
	
	for (int32 k = MAX_SLOT*MAX_SLOT-1; k>=0; k=k-8)
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
	//
	int32 IndexSlot = (AddPosition.x-1)*MAX_SLOT;
	for (int32 x = 0; x<MAX_SLOT; x++)
	{
		iDesc8x8[IndexSlot + x] = 1;
	}
}
//Заполнение полей по вертикале
void AQueenActor::VerticalFill(iPosition AddPosition)
{
	//				
	int32 IndexSlot = ((AddPosition.x-1)*MAX_SLOT +(AddPosition.y-1))- (AddPosition.x - 1) * MAX_SLOT;
	for (int32 y = 0; y<MAX_SLOT*MAX_SLOT; y+= MAX_SLOT)
	{
		iDesc8x8[IndexSlot + y] = 1;
	}
}
//Заполнение полей по диоганалям
void AQueenActor::DioganalFill(iPosition AddPosition)
{
	int32 IndexSlot = ((AddPosition.x - 1)*MAX_SLOT + (AddPosition.y - 1));
	
	while (IndexSlot<MAX_SLOT*MAX_SLOT && IndexSlot>=0)
	{
		iDesc8x8[IndexSlot] = 1;


		IndexSlot += MAX_SLOT-1;
		
		if ((IndexSlot + 1) % MAX_SLOT == 0)
		{
			break;
		}
		

	}

	IndexSlot = ((AddPosition.x - 1)*MAX_SLOT + (AddPosition.y - 1));

	
	while (IndexSlot<MAX_SLOT*MAX_SLOT&&IndexSlot>=0 )
	{
		iDesc8x8[IndexSlot] = 1;

		if ((IndexSlot + 1) % MAX_SLOT == 0)
		{
			break;
		}

		IndexSlot -= MAX_SLOT - 1;
		
	}

	IndexSlot = ((AddPosition.x - 1)*MAX_SLOT + (AddPosition.y - 1));

	while (IndexSlot<MAX_SLOT*MAX_SLOT && IndexSlot >= 0)
	{
		iDesc8x8[IndexSlot] = 1;

		if ((IndexSlot >= MAX_SLOT*MAX_SLOT - MAX_SLOT))
		{
			break;
		}
		
		IndexSlot += MAX_SLOT +1;

		
	}

	IndexSlot = ((AddPosition.x - 1)*MAX_SLOT + (AddPosition.y - 1));


	while (IndexSlot<MAX_SLOT*MAX_SLOT&&IndexSlot >= 0)
	{
		iDesc8x8[IndexSlot] = 1;

		if ((IndexSlot) % MAX_SLOT == 0)
		{
			break;
		}

		IndexSlot -= MAX_SLOT + 1;

	}
}
/*
*0   1  2  3  4  5  6  7
*8   9 10 11 12 13 14 15
*16 17 18 19 20 21 22 23
*24 25 26 27 28 29 30 31
*32	33 34 35 36 37 38 39
*40 41 42 43 44 45 46 47
*48 49 50 51 52 53 54 55
*56 57 58 59 60 61 62 63
 */