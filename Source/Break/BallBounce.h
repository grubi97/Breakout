// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallBounce.generated.h"

class UBoxComponent;
class APaddle_Player_Controller;

UCLASS()
class BREAK_API ABallBounce : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallBounce();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
		UBoxComponent* Box_Collision;


	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult);

	APaddle_Player_Controller* PlayerContoller_REF;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
