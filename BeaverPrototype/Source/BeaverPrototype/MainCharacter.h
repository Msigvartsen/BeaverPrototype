// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class BEAVERPROTOTYPE_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
<<<<<<< HEAD
	AMainCharacter();
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
=======
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
>>>>>>> 28f1eb51ebbe8340fa83cab74ab1dfd1fbdf8544
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere)
		UCameraComponent* PlayerCamera = nullptr;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* CameraBoom = nullptr;
<<<<<<< HEAD
	
	//Input Functions
	void MoveX(float value);
	void MoveY(float value);
	void Dodge();
	void Melee();
	void Shoot();
	void RotateToMousePosition();

	//Variables
	UPROPERTY(EditAnywhere)
		float DodgeSpeed = 4000.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UDecalComponent* CursorToWorld;
	UPROPERTY(EditAnywhere)
		float Stamina = 100.f;
	UPROPERTY(EditAnywhere)
		float MaxStamina = 100.f;
	UPROPERTY(EditAnywhere)
		float Health = 100.f;
	UPROPERTY(EditAnywhere)
		float MaxHealth = 100.f;

	UFUNCTION(BlueprintCallable, Category = "Stamina", meta = (AllowPrivateAccess = true))
		float GetStamina();
	UFUNCTION(BlueprintCallable, Category = "Health", meta = (AllowPrivateAccess = true))
		float GetHealth();
=======


	void MoveX(float value);
	void MoveY(float value);
	void LookYaw(float value);
	void Dodge();
	
>>>>>>> 28f1eb51ebbe8340fa83cab74ab1dfd1fbdf8544
};
