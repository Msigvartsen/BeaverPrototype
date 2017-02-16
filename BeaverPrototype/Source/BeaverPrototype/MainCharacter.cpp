
#include "BeaverPrototype.h"
#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	PlayerCamera->AttachTo(CameraBoom);

	/*CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());*/
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 2D mouse cords
	float X, Y;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(X, Y);
	FVector2D MouseLocation = FVector2D(X, Y);

	// SetActorRotation(PlayerToCursor.Rotation());
	const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
	const FVector2D  ViewportCenter = FVector2D(ViewportSize.X / 2, ViewportSize.Y / 2);
	FVector2D MouseDirection = MouseLocation - ViewportCenter;
	FVector RotationAngle = FVector(MouseDirection.X, MouseDirection.Y, 0);


	FRotator NewRotation = FMath::RInterpConstantTo(GetActorRotation(),RotationAngle.Rotation(),DeltaTime,340.f);
	GetWorld()->GetFirstPlayerController()->SetControlRotation(NewRotation);
	//SetActorRotation(NewRotation);

	//RotateToMousePosition();
	//Sets Stamina Regen
	if (Stamina < 100.f)
	{
		Stamina += 10.f * DeltaTime;
	}	
}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveX", this, &AMainCharacter::MoveX);
	InputComponent->BindAxis("MoveY", this, &AMainCharacter::MoveY);
	InputComponent->BindAction("Dodge", IE_Pressed, this, &AMainCharacter::Dodge);
	InputComponent->BindAction("Melee", IE_Pressed, this, &AMainCharacter::Melee);
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AMainCharacter::Shoot);
}

void AMainCharacter::MoveX(float value)
{
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

int AMainCharacter::GetInt()
{
	return 2;
}
