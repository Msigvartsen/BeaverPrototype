
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
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveX", this, &AMainCharacter::MoveX);
	InputComponent->BindAxis("MoveX", this, &AMainCharacter::MoveY);
	InputComponent->BindAxis("LookYaw", this, &AMainCharacter::LookYaw);
	InputComponent->BindAction("Dodge", IE_Pressed, this, &AMainCharacter::Dodge);
}

void AMainCharacter::MoveX(float value)
{

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