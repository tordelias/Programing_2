// Fill out your copyright notice in the Description page of Project Settings.


#include "Main.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include <UObject/ConstructorHelpers.h>
#include "Containers/Array.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AMain::AMain()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere.Init(NULL, 9);
	Sphere[0] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh1"));
	Sphere[1] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh2"));
	Sphere[2] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh3"));
	Sphere[3] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh4"));
	Sphere[4] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh5"));
	Sphere[5] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh6"));
	Sphere[6] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh7"));
	Sphere[7] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh8"));
	Sphere[8] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh9"));
	RootComponent = Sphere[4];
	for (int i{}; i < 9; i++)
	{
		if (i != 4)
		{
			Sphere[i]->SetupAttachment(GetRootComponent());
		}
	}

	//Sphere[i]->SetStaticMesh(MeshComponentAsset.Object);



	Red = CreateDefaultSubobject<UMaterial>(TEXT("RedMaterial"));
	Blue = CreateDefaultSubobject<UMaterial>(TEXT("BlueMaterial"));
	White = CreateDefaultSubobject<UMaterial>(TEXT("WhiteMaterial"));

	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 500.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	Sphere[0]->SetRelativeLocation(FVector(200.f, -200.f, 0.f));
	Sphere[1]->SetRelativeLocation(FVector(200.f, 0.f, 0.f));
	Sphere[2]->SetRelativeLocation(FVector(200.f, 200.f, 0.f));
	Sphere[3]->SetRelativeLocation(FVector(0.f, -200.f, 0.f));
	Sphere[4]->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	Sphere[5]->SetRelativeLocation(FVector(0.f, 200.f, 0.f));
	Sphere[6]->SetRelativeLocation(FVector(-200.f, -200.f, 0.f));
	Sphere[7]->SetRelativeLocation(FVector(-200.f, 0.f, 0.f));
	Sphere[8]->SetRelativeLocation(FVector(-200.f, 200.f, 0.f));

	TurnCounter = 0;
	RedWin = false; 
	BlueWin = false;
	SphereStatus.Init(NULL, 9);
	SphereB.Init(NULL, 9);
	SphereR.Init(NULL, 9);
}

// Called when the game starts or when spawned
void AMain::BeginPlay()
{
	Super::BeginPlay();

	Super::BeginPlay();

	for (int i{}; i < 9; i++)
	{
		Sphere[i]->SetMaterial(0, White);
	}
}

// Called every frame
void AMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("1", IE_Pressed, this, &AMain::OnePressed);
	PlayerInputComponent->BindAction("2", IE_Pressed, this, &AMain::TwoPressed);
	PlayerInputComponent->BindAction("3", IE_Pressed, this, &AMain::ThreePressed);
	PlayerInputComponent->BindAction("4", IE_Pressed, this, &AMain::FourPressed);
	PlayerInputComponent->BindAction("5", IE_Pressed, this, &AMain::FivePressed);
	PlayerInputComponent->BindAction("6", IE_Pressed, this, &AMain::SixPressed);
	PlayerInputComponent->BindAction("7", IE_Pressed, this, &AMain::SevenPressed);
	PlayerInputComponent->BindAction("8", IE_Pressed, this, &AMain::EightPressed);
	PlayerInputComponent->BindAction("9", IE_Pressed, this, &AMain::NinePressed);

}

void AMain::OnePressed()
{
	TurnController(0);
}

void AMain::TwoPressed()
{
	TurnController(1);
}

void AMain::ThreePressed()
{
	TurnController(2);
}

void AMain::FourPressed()
{
	TurnController(3);
}

void AMain::FivePressed()
{
	TurnController(4);
}

void AMain::SixPressed()
{
	TurnController(5);
}

void AMain::SevenPressed()
{
	TurnController(6);
}

void AMain::EightPressed()
{
	TurnController(7);
}

void AMain::NinePressed()
{
	TurnController(8);
}

void AMain::TurnController(int sphereindex)
{
	if ( RedWin != true)
	{
		if (SphereStatus[sphereindex] == true)
		{
			UE_LOG(LogTemp, Warning, TEXT("That index is already taken"));

			return;
		}


		if (TurnCounter % 2 == 0)
		{
			Sphere[sphereindex]->SetMaterial(0, Blue);
			SphereB[sphereindex] = 1;
		}
		else if (TurnCounter % 2 == 1)
		{
			Sphere[sphereindex]->SetMaterial(0, Red);
			SphereR[sphereindex] = 2;
		}
		SphereStatus[sphereindex] = true;
		TurnCounter++;
		WinChecker();
	}
}

void AMain::WinChecker()
{
	if (SphereB[0] + SphereB[1] + SphereB[2] == 3 || SphereB[0] + SphereB[4] + SphereB[8] == 3 || SphereB[0] + SphereB[3] + SphereB[6] == 3|| SphereB[2] + SphereB[4] + SphereB[6] == 3 || SphereB[3] + SphereB[4] + SphereB[5] == 3 || SphereB[6] + SphereB[7] + SphereB[8] == 3 || SphereB[1] + SphereB[4] + SphereB[5] == 3 || SphereB[2] + SphereB[5] + SphereB[8] == 3)
	{
		RedWin = true;
		UE_LOG(LogTemp, Warning, TEXT("BlueWins"));
	}
	if (SphereR[0] + SphereR[1] + SphereR[2] == 6 || SphereR[0] + SphereR[5] + SphereR[8] == 6 || SphereR[0] + SphereR[3] + SphereR[6] == 6 || SphereR[2] + SphereR[4] + SphereR[6] == 6 || SphereR[3] + SphereR[4] + SphereR[5] == 6 || SphereR[6] + SphereR[7] + SphereR[8] == 6 || SphereR[1] + SphereR[4] + SphereR[5] == 6 || SphereR[2] + SphereR[5] + SphereR[8] == 6)
	{
		RedWin = true;
		UE_LOG(LogTemp, Warning, TEXT("RedWins"));
	}
	if (TurnCounter == 9)
	{
		UE_LOG(LogTemp, Warning, TEXT("Draw"));
		RedWin = true;
	}


	//UE_LOG(LogTemp, Warning, TEXT("Enter function"));

	//if (SphereB[0] == 1 && SphereB[1] == 1 && SphereB[2] == 1)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("BlueWins"));
	//}
}

