// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class BEAVERPROTOTYPE_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AMainCharacter();
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere)
		UCameraComponent* PlayerCamera = nullptr;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* CameraBoom = nullptr;

	
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

	int GetInt();
};
