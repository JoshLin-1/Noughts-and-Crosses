// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Interact/InteractInterface.h"
#include "NewGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SUMMERHOMEWORK_API ANewGameMode : public AGameModeBase, public IInteractInterface
{
	GENERATED_BODY()


public:


	ANewGameMode();

	int Turn;
	bool Circle[9] {false, false, false, false, false, false, false, false, false};
	bool Cross[9]{false, false, false, false, false, false, false, false, false};
	
	
	void DefineTheTurn();

	void DoWeWin();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void WinUI();
	virtual void WinUI_Implementation();
	

	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void EqualUI();
	virtual void EqualUI_Implementation();
	


	UPROPERTY(EditAnywhere, Category = "PointToWin")
	int WinOrnot;
};
