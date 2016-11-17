// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Desc.h"


// Sets default values
ADesc::ADesc()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	mDescStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DescMesh"));
	RootComponent = mDescStaticMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh_Load(TEXT("StaticMesh'/Game/Geometry/Meshes/chess/desc.desc'"));
	mDescStaticMesh->SetStaticMesh(StaticMesh_Load.Object);
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> BlackMaterial_Load(TEXT("Material'/Game/Geometry/Meshes/chess/b_mat.b_mat'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> WhiteMaterial_Load(TEXT("Material'/Game/Geometry/Meshes/chess/w_mat.w_mat'"));

	mat_b = BlackMaterial_Load.Object;
	mat_w = WhiteMaterial_Load.Object;

	ResetMaterial(false);

}

// Called when the game starts or when spawned
void ADesc::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADesc::ResetMaterial(bool BlackMaterial)
{
	if (BlackMaterial)
	{
		
		mDescStaticMesh->SetMaterial(0, mat_b);
	}
	else
	{
		
		mDescStaticMesh->SetMaterial(0, mat_w);
	}
}

