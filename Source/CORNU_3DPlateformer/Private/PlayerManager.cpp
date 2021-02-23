// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerManager.h"

// Sets default values for this component's properties
UPlayerManager::UPlayerManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;


	// Initializing variables
	MaxHealth = 3.f;
	CurrentHealth = MaxHealth;

	bIsDead = false;
}


// Called when the game starts
void UPlayerManager::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();

	if (Owner)
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UPlayerManager::TakeDamage);
	}
}

void UPlayerManager::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0)
	{
		return;
	}

	AActor* AOwner = GetOwner();
	
	/*if (AOwner)
	{
		Player = Cast<APlayerCharacter>(AController::GetCharacter());

		if (Player)
		{
			CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);

			if (CurrentHealth <= 0.f)
			{
				bIsDead = true;
			}

			Player.CameraFade_BP();
		}
	}*/
}
