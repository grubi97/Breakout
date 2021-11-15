// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APaddle::APaddle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Padle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Padle"));
	RootComponent = SM_Padle;

	SM_Padle->SetEnableGravity(false);//no gravity 
	SM_Padle->SetConstraintMode(EDOFMode::XZPlane);//not going up and down;
	SM_Padle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);//solid physic body
	SM_Padle->SetCollisionProfileName(TEXT("PhysicsActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));

}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APaddle::MoveHorizontal(float AxisValue)
{
	AddMovementInput(FVector(AxisValue, 0.0f, 0.0f), 1.0f, false);//movinf acros xaxis left and right, scale wont change and no force
}

