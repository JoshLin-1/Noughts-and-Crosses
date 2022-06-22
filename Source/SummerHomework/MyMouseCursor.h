// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyMouseCursor.generated.h"

UCLASS()
class SUMMERHOMEWORK_API AMyMouseCursor : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyMouseCursor();
	
	UPROPERTY (EditAnywhere, Category = "Camer")
	class UCameraComponent* CameraComp;

	UPROPERTY (EditAnywhere, Category = "Convert")
	class APlayerController* PlayerCont;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void InteractPressed();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Distance")
	float TraceDistance; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Turn")
	bool CircleOrNot;

	UFUNCTION(BlueprintNativeEvent)
	void TraceForward();
	void TraceForward_Implementation();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	AActor* FocusedActor;

	FHitResult HitResult;

	AActor* Interactable;

	AActor* Reflection;

};
