// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Door.generated.h"

UCLASS()
class FPS_TEST_C_API ADoor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot = nullptr;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Door = nullptr;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorFrame = nullptr;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxTrigger = nullptr;

public:	
	// Sets default values for this actor's properties
	ADoor();

	UPROPERTY(EditAnywhere, Category = "MyVariables")
	bool isClosed = false;

	UFUNCTION()
	void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
