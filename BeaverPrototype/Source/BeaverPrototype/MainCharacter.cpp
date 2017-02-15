
#include "BeaverPrototype.h"
#include "MainCharacter.h"


<<<<<<< HEAD
=======
// Sets default values
>>>>>>> 28f1eb51ebbe8340fa83cab74ab1dfd1fbdf8544
AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	PlayerCamera->AttachTo(CameraBoom);
<<<<<<< HEAD

	/*CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());*/
=======
>>>>>>> 28f1eb51ebbe8340fa83cab74ab1dfd1fbdf8544
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
<<<<<<< HEAD
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
=======
	
>>>>>>> 28f1eb51ebbe8340fa83cab74ab1dfd1fbdf8544
}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

<<<<<<< HEAD
	FVector MouseLocation;
	FVector MouseDirection;
	GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);
	SetActorRotation(FRotator(0, MouseDirection.Rotation().Yaw, 0));

	//RotateToMousePosition();
	//Sets Stamina Regen
	if (Stamina < 100.f)
	{
		Stamina += 10.f * DeltaTime;
	}	
=======
>>>>>>> 28f1eb51ebbe8340fa83cab74ab1dfd1fbdf8544
}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveX", this, &AMainCharacter::MoveX);
<<<<<<< HEAD
	InputComponent->BindAxis("MoveY", this, &AMainCharacter::MoveY);
	InputComponent->BindAction("Dodge", IE_Pressed, this, &AMainCharacter::Dodge);
	InputComponent->BindAction("Melee", IE_Pressed, this, &AMainCharacter::Melee);
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AMainCharacter::Shoot);
=======
	InputComponent->BindAxis("MoveX", this, &AMainCharacter::MoveY);
	InputComponent->BindAxis("LookYaw", this, &AMainCharacter::LookYaw);
	InputComponent->BindAction("Dodge", IE_Pressed, this, &AMainCharacter::Dodge);
>>>>>>> 28f1eb51ebbe8340fa83cab74ab1dfd1fbdf8544
}

void AMainCharacter::MoveX(float value)
{
<<<<<<< HEAD
	AddMovementInput(FVector::ForwardVector, value);
}

void AMainCharacter::MoveY(float value)
{
	AddMovementInput(FVector::RightVector, value);
}

void AMainCharacter::Melee()
{
	UE_LOG(LogTemp,Warning,TEXT("Melee combat! PEWPEW"))
}

void AMainCharacter::Shoot()
{
	UE_LOG(LogTemp,Warning,TEXT("Shooting! BZT BZT"))
}

void AMainCharacter::Dodge( )
{
	if (Stamina > 40.f)
	{
		FVector DodgeDirection(0, 0, 0);
		DodgeDirection += FVector::ForwardVector * InputComponent->GetAxisValue("MoveX");
		DodgeDirection += FVector::RightVector * InputComponent->GetAxisValue("MoveY");
		DodgeDirection.Normalize();
		LaunchCharacter((DodgeDirection*DodgeSpeed), true, false);
		Stamina -= 40.f;
	}
}

void AMainCharacter::RotateToMousePosition()
{
	FHitResult Hit;
	bool HitResult = false;

	HitResult = GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel(
				UEngineTypes::ConvertToTraceType(ECC_WorldStatic), true, Hit);

	if (HitResult)
	{
		FVector CursorFV = Hit.ImpactNormal;
		FRotator CursorR = CursorFV.Rotation();
		CursorToWorld->SetWorldLocation(Hit.Location);
		CursorToWorld->SetWorldRotation(CursorR);
		FVector CursorLocation = Hit.Location;
		UE_LOG(LogTemp, Warning, TEXT("Cursor location %s!"), *CursorLocation.ToString());
		FVector TempLocation = FVector(CursorLocation.X, CursorLocation.Y, 30.f);
		FVector NewDirection = TempLocation - GetActorLocation();
		NewDirection.Z = 0.f;
		NewDirection.Normalize();
		SetActorRotation(NewDirection.Rotation());
	}
}

float AMainCharacter::GetStamina()
{
	return (Stamina / MaxStamina);
}

float AMainCharacter::GetHealth()
{
	return (Health / MaxHealth);
}
=======

}

void AMainCharacter::MoveY(float value)
{

}

void AMainCharacter::LookYaw(float value)
{

}

void AMainCharacter::Dodge()
{

}
>>>>>>> 28f1eb51ebbe8340fa83cab74ab1dfd1fbdf8544
