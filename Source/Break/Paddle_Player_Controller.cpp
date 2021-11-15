// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_Player_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Paddle.h"
#include "Ball.h"

APaddle_Player_Controller::APaddle_Player_Controller()
{


}


void APaddle_Player_Controller::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);//all classes of the scene, for here specific is camera, store in cameraactors

	FViewTargetTransitionParams Params;// A set of parameters to describe how to transition between view targets
	SetViewTarget(CameraActors[0], Params);//which camera is gonna display the game

	SpawnNewBall();
}

void APaddle_Player_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);//to detect input in player controller

	InputComponent->BindAxis("MoveHorizontal", this, &APaddle_Player_Controller::MoveHorizontal);//MoveHorizontal is from inputsettings
	InputComponent->BindAction("Launch", IE_Pressed,this, &APaddle_Player_Controller::Launch);
}



void APaddle_Player_Controller::MoveHorizontal(float AxisValue)
{
	FConstPawnIterator it = GetWorld()->GetPawnIterator();
	APaddle* MyPawn = Cast<APaddle>(it->Get());//get all pawns in the game

	if (MyPawn) {
		MyPawn->MoveHorizontal(AxisValue);
	}
}

void APaddle_Player_Controller::Launch()
{
	MyBall->Launch();
}

void APaddle_Player_Controller::SpawnNewBall()
{
	if (!MyBall) { MyBall = nullptr; }
	if (Ballobj)
	{
		MyBall = GetWorld()->SpawnActor<ABall>(Ballobj,SpawnLocation,SpawnRotation,SpawnInfo);
	}
}
