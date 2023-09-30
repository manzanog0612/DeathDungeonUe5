// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullets.h"

#include "fps_test_cCharacter.h"

void ABullets::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent,
								  AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->Tags.Contains("Player"))
	{
		ACollectable::OnTriggerBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
		Collect();
	}
}

void ABullets::Collect()
{
	Afps_test_cCharacter* player = Cast<Afps_test_cCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	player->SetBulletsAmount(player->GetBulletsAmount() + 25);
	ACollectable::Collect();
}