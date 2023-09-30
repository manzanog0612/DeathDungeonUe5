// Fill out your copyright notice in the Description page of Project Settings.

#include "Collectable.h"

#include "Components/BoxComponent.h"

// Sets default values
ACollectable::ACollectable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	CollectableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollectableSM"));
	CollectableMesh->SetupAttachment(RootComponent);

	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxTrigger"));
	BoxTrigger->SetBoxExtent(FVector(300.f));
	BoxTrigger->SetupAttachment(RootComponent);	
}

// Called when the game starts or when spawned
void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &ACollectable::OnTriggerBeginOverlap);
	BoxTrigger->OnComponentEndOverlap.AddDynamic(this, &ACollectable::OnTriggerEndOverlap);
}

// Called every frame
void ACollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACollectable::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	EnableInput(GetWorld()->GetFirstPlayerController());
}

void ACollectable::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	DisableInput(GetWorld()->GetFirstPlayerController());
}

void ACollectable::Collect()
{
	Destroy();
}

