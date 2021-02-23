// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "Components/ActorComponent.h"
#include "PlayerManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CORNU_3DPLATEFORMER_API UPlayerManager : public UActorComponent
{
	GENERATED_BODY()


private:
	// Variables
	int PlayerScore;

	UPROPERTY()
		APlayerCharacter* Player;

public:	
	// Sets default values for this component's properties
	UPlayerManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	//
	bool bIsDead;


	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float MaxHealth;

	UPROPERTY(BlueprintReadOnly)
		float CurrentHealth;

	UFUNCTION()
		void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
};
