// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "fps_test_cCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UAnimMontage;
class USoundBase;

UCLASS(config=Game)
class Afps_test_cCharacter : public ACharacter
{
	GENERATED_BODY()	

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	
public:
	Afps_test_cCharacter();

protected:
	virtual void BeginPlay();

public:
	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;
	
	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/** Bool for AnimBP to switch to another animation set */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon)
	bool bHasRifle;
	
	/** Setter to set the health */
	UFUNCTION(BlueprintCallable, Category = Character)
	void SetHealth(float h);
	
	/** Getter to get the health */
	UFUNCTION(BlueprintCallable, Category = Character)
	float GetHealth();
	
	/** Setter to set the damage */
	UFUNCTION(BlueprintCallable, Category = Character)
	void SetDamage(float h);

	/** Getter to get isDead */
	UFUNCTION(BlueprintCallable, Category = Character)
	bool GetIsDead();
	
	/** Setter to set the bullets */
	UFUNCTION(BlueprintCallable, Category = Character)
	void SetBulletsAmount(int b);

	/** Getter to get the bullets */
	UFUNCTION(BlueprintCallable, Category = Character)
	int GetBulletsAmount();

	/** Getter to get the bullets */
	UFUNCTION(BlueprintCallable, Category = Character)
	bool Shoot();
	
	/** Setter to set the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void SetHasRifle(bool bNewHasRifle);

	/** Getter for the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	bool GetHasRifle();

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface
	
private:
	/** Health of the player*/
	float health;

	/** Bullets of the player*/
	int bullets;

	bool isDead;
	
public:
	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
};

