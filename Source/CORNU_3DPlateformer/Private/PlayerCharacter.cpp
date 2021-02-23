// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Set the main variables to default
	bIsWalking = false;
	ZBorder = -3000.f;

	MaxHealth = 3.f;
	CurrentHealth = MaxHealth;

	bIsDead = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	this->OnTakeAnyDamage.AddDynamic(this, &APlayerCharacter::TakeDamage);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::MouseXControl);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::MouseYControl);

	PlayerInputComponent->BindAction("Walk", IE_Pressed, this, &APlayerCharacter::StartWalking);
	PlayerInputComponent->BindAction("Walk", IE_Released, this, &APlayerCharacter::StopWalking);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}


// Move functions
void APlayerCharacter::MoveForward(float AxisValue)
{
	if (bIsDead == true)
	{
		return;
	}

	if (bIsWalking)
	{
		AxisValue = AxisValue / 2;
	}

	AddMovementInput(this->GetActorForwardVector(), AxisValue);
}

void APlayerCharacter::MoveRight(float AxisValue)
{
	if (bIsDead == true)
	{
		return;
	}

	if (bIsWalking)
	{
		AxisValue = AxisValue / 2;
	}

	AddMovementInput(this->GetActorRightVector(), AxisValue);
}


// Walk functions
void APlayerCharacter::StartWalking()
{
	bIsWalking = true;
}

void APlayerCharacter::StopWalking()
{
	bIsWalking = false;
}


// Turn functions
// Horizontal
void APlayerCharacter::MouseXControl(float AxisValue)
{
	FMath::Clamp(AxisValue, -2.f, 2.f);
	AddControllerYawInput(AxisValue);
}

// Vertical
void APlayerCharacter::MouseYControl(float AxisValue)
{
	FMath::Clamp(AxisValue, -0.4f, 0.4f);
	AddControllerPitchInput(-AxisValue);
}


// DamageManager
void APlayerCharacter::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0)
	{
		return;
	}

	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);

	if (CurrentHealth <= 0.f)
	{
		bIsDead = true;
		CameraFade_BP();
	}
}


// Getters
bool APlayerCharacter::GetIsDead() const
{
	return bIsDead;
}