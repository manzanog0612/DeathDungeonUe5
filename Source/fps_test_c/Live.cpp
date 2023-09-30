// Fill out your copyright notice in the Description page of Project Settings.
#include "Live.h"
#include "fps_test_cCharacter.h"

void ALive::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent,
                                  AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->Tags.Contains("Player"))
	{
		ACollectable::OnTriggerBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
		Collect();
	}
}

void ALive::Collect()
{
	Afps_test_cCharacter* player = Cast<Afps_test_cCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	player->SetHealth(player->GetHealth() + 10);
	ACollectable::Collect();
}