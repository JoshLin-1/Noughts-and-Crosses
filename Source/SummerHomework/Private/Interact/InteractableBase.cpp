// Fill out your copyright notice in the Description page of Project Settings.


#include "Interact/InteractableBase.h"
#include "MyGameStateBase.h"
#include "NewGameMode.h"


// Sets default values
AInteractableBase::AInteractableBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AInteractableBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractableBase::OnInteract_Implementation(AActor* Caller)
{

	if(ANewGameMode* GM = Cast<ANewGameMode>(GetWorld()->GetAuthGameMode()))
	{
		if (NotClickAgain)
		{
			if (GM->Turn == 0)
			{
				GM->Circle[BoxPoint] =true;
				GM->DefineTheTurn();
				GM->DoWeWin();
				// GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Cyan, FString::Printf(TEXT("You Click Circle No.%d box"), BoxPoint));
			}
			else
			{
				GM->Cross[BoxPoint] =true;
				GM->DefineTheTurn();
				GM->DoWeWin();
				// GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red, FString::Printf(TEXT("You Click Cross No.%d box"), BoxPoint));
			}

			NotClickAgain = false;

		}

		
	}
	// else
	// {
	// 	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, TEXT("GM->DefineTheTurn Fail"));
	// }
	
	
}

void AInteractableBase::StartFocus_Implementation()
{
	// GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, TEXT("StartFocus"));
}


void AInteractableBase::EndFocus_Implementation()
{
	// GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("EndFocus"));

}

void AInteractableBase::Circle_Implementation()
{
	// GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Circle"));
}

void AInteractableBase::Cross_Implementation()
{
	// GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Cross"));

}

void AInteractableBase::CrossInClick_Implementation()
{

}

void AInteractableBase::CircleInClick_Implementation()
{

}