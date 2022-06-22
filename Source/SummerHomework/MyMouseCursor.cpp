// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMouseCursor.h"
#include "Interact/InteractInterface.h"
#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameStateBase.h"
#include "NewGameMode.h"


// Sets default values
AMyMouseCursor::AMyMouseCursor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComp = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(RootComponent);
	TraceDistance = 2000.f;



	
}

// Called when the game starts or when spawned
void AMyMouseCursor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyMouseCursor::InteractPressed()
{
	TraceForward();//可能要放到裡面
	
	if (FocusedActor)
		{
			IInteractInterface* Interface = Cast<IInteractInterface>(FocusedActor);
			
			if (Interface)
			{	
				
				Interface->Execute_EndFocus(FocusedActor);
				Interface->Execute_OnInteract(FocusedActor, this);

				if(ANewGameMode* GM = Cast<ANewGameMode>(GetWorld()->GetAuthGameMode()))
				{
					if(GM->Turn==0)
					{
						CircleOrNot = false;
						Interface->Execute_CrossInClick(Interactable);
					}
					else
					{
						CircleOrNot = true;
						Interface->Execute_CircleInClick(Interactable);
					}

				}
			}
		}
	
	// else
	// {
	// 	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("GM->Turn Fail"));
	// }
}

void AMyMouseCursor::TraceForward_Implementation()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	PlayerController->bShowMouseCursor = true;
	PlayerController->bEnableMouseOverEvents = false;
	

	int32 ViewportSizeX, ViewportSizeY;
	PlayerController->GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX, ViewportSizeY);

	FVector WorldLocation;
	FVector WorldDirection;

	if (PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("WorldLocation: %s"), *WorldLocation.ToString());
	}

	FVector StartLocation(WorldLocation.Z, WorldLocation.X, WorldLocation.Y);
	FVector endLocation = StartLocation+ (WorldDirection*TraceDistance);

	FCollisionQueryParams TraceParms;
	// FHitResult HitResult;

	GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation, endLocation, ECC_Visibility, TraceParms);

	// DrawDebugLine(GetWorld(), WorldLocation, endLocation, FColor::Orange, false, 2.f);
	Interactable = HitResult.GetActor();

	// GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, FString::Printf(TEXT("WorldLocation: %s"), *WorldLocation.ToString()));

	// if(bHit)
	// {
		// DrawDebugBox(GetWorld(), HitResult.ImpactPoint, FVector(5,5,5), FColor::Emerald, false, 2.f);
		// AActor* Interactable = HitResult.GetActor();
		

		if (Interactable)
		{
			if (Interactable != FocusedActor)
			{
				
				if (FocusedActor)
				{
				
					IInteractInterface* Interface = Cast<IInteractInterface>(FocusedActor);
					if (Interface)
					{
						Interface->Execute_EndFocus(FocusedActor);
						
					}
					
				}

				IInteractInterface* Interface = Cast<IInteractInterface>(Interactable);
				
				if (Interface)
				{
					Interface->Execute_StartFocus(Interactable);
					if (CircleOrNot)
					{
						Interface->Execute_Cross(Interactable);
					}
					else
					{
						Interface->Execute_Circle(Interactable);
					}
				}
				FocusedActor = Interactable; 
			}
		}
		else
		{
			
			if (FocusedActor)
			{
				
				IInteractInterface* Interface = Cast<IInteractInterface>(FocusedActor); 		
				Interface->Execute_EndFocus(FocusedActor);
					
				
				FocusedActor = nullptr; 
			}
		}
}
// Called every frame
void AMyMouseCursor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TraceForward();
	

}

// Called to bind functionality to input
void AMyMouseCursor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Click", IE_Pressed, this, &AMyMouseCursor::InteractPressed);
}

