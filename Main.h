// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Main.generated.h"	

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class MYFIRSTGAME_API AMain : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	TArray<UStaticMeshComponent*> Sphere;
private:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere, Category = "A")
		UMaterial* Red;
	UPROPERTY(EditAnywhere, Category = "A")
		UMaterial* Blue;
	UPROPERTY(EditAnywhere, Category = "A")
		UMaterial* White;

	int TurnCounter;
	bool RedWin;
	bool BlueWin;

	TArray<bool> SphereStatus;
	TArray<int> SphereB;
	TArray<int> SphereR;

	void OnePressed();
	void TwoPressed();
	void ThreePressed();
	void FourPressed();
	void FivePressed();
	void SixPressed();
	void SevenPressed();
	void EightPressed();
	void NinePressed();
	void TurnController(int sphereindex);
	void WinChecker();
};
