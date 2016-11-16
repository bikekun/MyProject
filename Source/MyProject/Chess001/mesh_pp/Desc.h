// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Desc.generated.h"

UCLASS()
class MYPROJECT_API ADesc : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADesc();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Root)
		UStaticMeshComponent* mDescStaticMesh;

	void ResetMaterial(bool BlackMaterial);

	
	
};
