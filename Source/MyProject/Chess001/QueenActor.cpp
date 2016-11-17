// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "QueenActor.h"
#include "Engine.h"




// Sets default values
AQueenActor::AQueenActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StartPosition.x = 1;
	StartPosition.y = 1;

	///////////////////////
	// компоненты

	
	

	/*m_desc = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh_Load(TEXT("StaticMesh'StaticMesh'/Game/Geometry/Meshes/chess/desc.desc''"));
	m_desc->SetStaticMesh(StaticMesh_Load.Object);*/

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	RootComponent = BoxComp;
	BoxComp->SetBoxExtent(FVector((800.000000, 800.000000, 100.000000)));

	static ConstructorHelpers::FClassFinder<ADesc>
		ProjectileBP(TEXT("Class'/Script/MyProject.Desc'"));
	pDesc = ProjectileBP.Class;

	

	
	
}

// Called when the game starts or when spawned
void AQueenActor::BeginPlay()
{
	Super::BeginPlay();
	FullFill(StartPosition);
	iDescQueen[((StartPosition.x-1)*MAX_SLOT + (StartPosition.y-1))] = QUEEN;
	colQueen++;


	

	
	
}
void AQueenActor::OnConstruction(const FTransform& transform) {
	Super::OnConstruction(transform);

	int32 index = 0;


	//SPrintResult();
	UWorld* const World = GetWorld();

	/*FActorSpawnParameters SpawnParams;
	SpawnParams.Name = "1";
	SpawnParams.Owner = this;
	SpawnParams.bNoCollisionFail = true;*/
	if (World != NULL)

		for (int x = 0; x < MAX_SLOT; x++)
		{
			for (int y = 0; y < MAX_SLOT; y++)
			{
				const FRotator SpawnRotation = FRotator::ZeroRotator;
				const FVector SpawnLocation = RootComponent->GetComponentLocation() + FVector((200 * x) - (200 * MAX_SLOT / 2), (200 * y) - (200 * MAX_SLOT / 2), 0.f);



				ADesc *op = World->SpawnActor<ADesc>(pDesc, SpawnLocation, SpawnRotation);//, SpawnParams);




				if (index % 2 == 0)
					op->ResetMaterial(false);
				else
					op->ResetMaterial(true);

				index++;



			}
			index++;
		}//for

}

// Called every frame
void AQueenActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	

	if ((!bDescEnd)/*&& ThisSlot >=0 && ThisSlot<MAX_SLOT*MAX_SLOT*/&&StartPosition.x<=MAX_SLOT&&StartPosition.y<=MAX_SLOT)
	{
		
		
		if (SpawnQueen(ThisSlot)) 
		{
			colQueen++;
		}

		ThisSlot++;
	}
	else if (StartPosition.x<=MAX_SLOT&&StartPosition.y<=MAX_SLOT)
	{
		ClearDesc();

		
	}

	SPrintResult();
	SPrintQueen(colQueen);

	if (bestColQueen>=0)
	{
		SPrintBest();
	}

}
//вывод на экран
void AQueenActor::SPrintResult()
{
	/////////////////////
	//iPosition pos;
	//pos.x = 4;
	//pos.y = 4;
	//
	//FullFill(pos);

	//pos.x = 2;
	//pos.y = 7;

	//FullFill(pos);
	///////////////////
	
	for (int32 k = MAX_SLOT*MAX_SLOT-1; k>=0; k=k-8)
	{
		
			GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("%d;%d;%d;%d;%d;%d;%d;%d"), 
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

void AQueenActor::SPrintQueen(int32 value)
{
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Black, FString::Printf(TEXT("Количество ферзей: %d"), value));

	for (int32 k = MAX_SLOT*MAX_SLOT - 1; k >= 0; k = k - 8)
	{
		
		GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Black, FString::Printf(TEXT("%d;%d;%d;%d;%d;%d;%d;%d"),
			iDescQueen[k - 7],
			iDescQueen[k - 6],
			iDescQueen[k - 5],
			iDescQueen[k - 4],
			iDescQueen[k - 3],
			iDescQueen[k - 2],
			iDescQueen[k - 1],
			iDescQueen[k]));

	}
}

void AQueenActor::SPrintBest()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Yellow, FString::Printf(TEXT("Количество ферзей: %d"), bestColQueen));
	for (int32 k = MAX_SLOT*MAX_SLOT - 1; k >= 0; k = k - 8)
	{

		GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Black, FString::Printf(TEXT("%d;%d;%d;%d;%d;%d;%d;%d"),
			iBestDesc[k - 7],
			iBestDesc[k - 6],
			iBestDesc[k - 5],
			iBestDesc[k - 4],
			iBestDesc[k - 3],
			iBestDesc[k - 2],
			iBestDesc[k - 1],
			iBestDesc[k]));

	}
}


//очистка положения на доске
void AQueenActor::ClearDesc()
{
	if (colQueen > bestColQueen)
	{
		bestColQueen = colQueen;
		
		for (int32 i = 0; i < MAX_SLOT*MAX_SLOT; i++)
		{
			iBestDesc[i] = iDescQueen[i];
		}
		
	}


	for (int32 i = 0; i< MAX_SLOT*MAX_SLOT; i++)
	{
		iDesc8x8[i] = 0;
	}

	StartPosition.x++;

	if (StartPosition.x>MAX_SLOT)
	{
		StartPosition.x = 1;
		StartPosition.y++;
	}

	if (StartPosition.y > MAX_SLOT)
	{
		/*StartPosition.x = 1;
		StartPosition.y = 1;*/
	}

	for (int32 i = 0; i< MAX_SLOT*MAX_SLOT; i++)
	{
		iDescQueen[i] = 0;
	}
	colQueen = 0;
	bDescEnd = false;
	ThisSlot = 0;

	FullFill(StartPosition);
	iDescQueen[((StartPosition.x - 1)*MAX_SLOT + (StartPosition.y - 1))] = QUEEN;
	colQueen++;
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

void AQueenActor::FullFill(iPosition addPosition)
{
	HorisontFill(addPosition);
	VerticalFill(addPosition);
	DioganalFill(addPosition);
}

bool AQueenActor::SpawnQueen(int32 newPosition)
{
	/*GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT(" %d"), newPosition));*/
	/*FullFill(StartPosition);
	iDescQueen[((StartPosition.x - 1)*MAX_SLOT + (StartPosition.y - 1))] = QUEEN;*/

	if (newPosition>=MAX_SLOT*MAX_SLOT)
	{
		bDescEnd = true;
		return false;
	}
	else if (iDesc8x8[newPosition] == 0)
	{
		iPosition nPos;
		nPos.x = (newPosition / MAX_SLOT) + 1;
		nPos.y = (newPosition - (nPos.x-1)*MAX_SLOT)+1;

		FullFill(nPos);
		iDescQueen[newPosition] = QUEEN;

		/*GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::White, FString::Printf(TEXT(" %d"), newPosition));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, FString::Printf(TEXT(" %d,%d"), nPos.x, nPos.y));*/

		return true;
	}

	return false;
	
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
