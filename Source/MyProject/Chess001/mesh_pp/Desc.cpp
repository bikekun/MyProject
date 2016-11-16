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

	ResetMaterial(true);

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
		static ConstructorHelpers::FObjectFinder<UMaterialInterface> BlackMaterial_Load(TEXT("Material'/Game/Geometry/Meshes/chess/b_mat.b_mat'"));
		mDescStaticMesh->SetMaterial(0, BlackMaterial_Load.Object);
	}
	else
	{
		static ConstructorHelpers::FObjectFinder<UMaterialInterface> WhiteMaterial_Load(TEXT("Material'/Game/Geometry/Meshes/chess/w_mat.w_mat'"));
		mDescStaticMesh->SetMaterial(0, WhiteMaterial_Load.Object);
	}
}

