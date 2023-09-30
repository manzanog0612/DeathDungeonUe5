// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Collectable.generated.h"

UCLASS()
class FPS_TEST_C_API ACollectable : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot = nullptr;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CollectableMesh = nullptr;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxTrigger = nullptr;
	
public:	
	ACollectable();
	
	UFUNCTION()
	virtual void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
		
	UFUNCTION()
	virtual void Collect();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
