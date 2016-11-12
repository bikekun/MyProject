// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "QueenActor.generated.h"

#define MAX_SLOT 8
#define QUEEN 1


struct iPosition
{
	int32 x, y;
};


UCLASS()
class MYPROJECT_API AQueenActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQueenActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Вывод на экран результата
	void SPrintResult();
	void SPrintQueen(int32 colQueen);
	//очистка доски
	void ClearDesc();

	void HorisontFill(iPosition AddPosition);
	void VerticalFill(iPosition AddPosition);
	void DioganalFill(iPosition AddPosition);
	void FullFill(iPosition addPosition);

	//установка ферзей
	bool SpawnQueen(int32 newPosition);
	//доска с битыми полями
	int32 iDesc8x8 [MAX_SLOT*MAX_SLOT] = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		
	};
	//растоновка ферзей
	int32 iDescQueen [MAX_SLOT*MAX_SLOT] = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,

	};

	iPosition StartPosition;
	bool bDescEnd = false;
	int32 colQueen = 0;
	int32 ThisSlot = 0;
};
