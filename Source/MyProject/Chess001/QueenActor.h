// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "mesh_pp/Desc.h"
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
	virtual void Tick(float DeltaSeconds) override;

	// ����� �� ����� ����������
	void SPrintResult();
	void SPrintQueen(int32 value);
	void SPrintBest();
	//������� �����
	void ClearDesc();

	void HorisontFill(iPosition AddPosition);
	void VerticalFill(iPosition AddPosition);
	void DioganalFill(iPosition AddPosition);
	void FullFill(iPosition addPosition);

	//��������� ������
	bool SpawnQueen(int32 newPosition);
	//����� � ������ ������
	int32 iDesc8x8[MAX_SLOT*MAX_SLOT] = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,

	};
	//���������� ������
	int32 iDescQueen[MAX_SLOT*MAX_SLOT] = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,

	};

	int32 iBestDesc[MAX_SLOT*MAX_SLOT] = {
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
	int32 bestColQueen = -1;


	///////////////////////
	// ����������

	/*UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = StaticMeshAssets)
		UStaticMeshComponent* m_desc;*/

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Root)
		UBoxComponent* BoxComp;

	
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TArray<UStaticMeshComponent*> pDesc;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TArray<UStaticMeshComponent*> ObjectQueen;

	TArray<UStaticMeshComponent*> QueenMesh;

	void MoveQueen();

	UMaterialInterface *mat_b;
	UMaterialInterface *mat_w;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	UStaticMeshComponent* op;
	virtual void OnConstruction(const FTransform& transform) override;
	
};
