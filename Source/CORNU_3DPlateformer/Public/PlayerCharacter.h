// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
// #include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class CORNU_3DPLATEFORMER_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()


private:
	// Variables
	bool bIsWalking;

	float ZBorder;


	// The function to move the player forward or backward
	void MoveForward(float AxisValue);

	// The function to move the player sideways
	void MoveRight(float AxisValue);

	// The function to turn the camera horizontally
	void MouseXControl(float AxisValue);

	// The function to look up and down
	void MouseYControl(float AxisValue);

	// Walk functions
	void StartWalking();

	void StopWalking();


public:
	// Sets default values for this character's properties
	APlayerCharacter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//
	UPROPERTY(BlueprintReadOnly)
		bool bIsDead;


	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float MaxHealth;

	UPROPERTY(BlueprintReadOnly)
		float CurrentHealth;

	UFUNCTION()
		void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(BlueprintImplementableEvent)
		void CameraFade_BP();

	UFUNCTION(BlueprintPure)
		bool GetIsDead() const;
};
