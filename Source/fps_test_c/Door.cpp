// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorSM"));
	Door->SetupAttachment(RootComponent);

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameSM"));
	DoorFrame->SetupAttachment(RootComponent);

	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxTrigger"));
	BoxTrigger->SetBoxExtent(FVector(300.f));
	BoxTrigger->SetupAttachment(RootComponent);	
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &ADoor::OnTriggerBeginOverlap);
	BoxTrigger->OnComponentEndOverlap.AddDynamic(this, &ADoor::OnTriggerEndOverlap);
}

void ADoor::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, FString("IN"));
	EnableInput(GetWorld()->GetFirstPlayerController());
}

void ADoor::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, FString("OUT"));
	DisableInput(GetWorld()->GetFirstPlayerController());
}