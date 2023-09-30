// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectable.h"
#include "Bullets.generated.h"

/**
 * 
 */
UCLASS()
class FPS_TEST_C_API ABullets : public ACollectable
{
	GENERATED_BODY()
public:	
	virtual void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
	virtual void Collect() override;
};
