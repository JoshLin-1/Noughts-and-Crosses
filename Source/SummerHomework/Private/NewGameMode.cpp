// Fill out your copyright notice in the Description page of Project Settings.


#include "NewGameMode.h"
#include "MyGameStateBase.h"
#include "Interact/InteractableBase.h"
#include "MenuHUD.h"
#include "MenuPlayerController.h"

ANewGameMode::ANewGameMode()
{
    GameStateClass = AMyGameStateBase::StaticClass();
    PlayerControllerClass = AMenuPlayerController::StaticClass();
    HUDClass = AMenuHUD::StaticClass();
}

void ANewGameMode::DefineTheTurn()
{
    
    if (AMyGameStateBase*GM = Cast<AMyGameStateBase>(GameState))
    {
        
        Turn = GM->DefineTurn%2;
        GM->DefineTurn++;
            
        
            
    }

   
    
   
}

void ANewGameMode::DoWeWin()
{
AMyGameStateBase*GM = Cast<AMyGameStateBase>(GameState);
//   int wintarget[8][3]= {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7}, {2, 5, 8}, {3,6, 9}, {1, 5, 9}, {3, 5, 7}};


if ((Circle[1]==true&&Circle[2]==true&&Circle[3]==true)||(Circle[4]==true&&Circle[5]==true&&Circle[6]==true)||(Circle[7]==true&&Circle[8]==true&&Circle[9]==true)||(Circle[1]==true&&Circle[4]==true&&Circle[7]==true)||(Circle[2]==true&&Circle[5]==true&&Circle[8]==true)||(Circle[3]==true&&Circle[6]==true&&Circle[9]==true)||(Circle[1]==true&&Circle[5]==true&&Circle[9]==true)||(Circle[3]==true&&Circle[5]==true&&Circle[7]==true))
{
    // GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Cyan, TEXT("Circle win"));
    WinUI();
    // if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(GetHUD()))
    // {
    //     MenuHUD->EndMenu();
    // }
}

else if ((Cross[1]==true&&Cross[2]==true&&Cross[3]==true)||(Cross[4]==true&&Cross[5]==true&&Cross[6]==true)||(Cross[7]==true&&Cross[8]==true&&Cross[9]==true)||(Cross[1]==true&&Cross[4]==true&&Cross[7]==true)||(Cross[2]==true&&Cross[5]==true&&Cross[8]==true)||(Cross[3]==true&&Cross[6]==true&&Cross[9]==true)||(Cross[1]==true&&Cross[5]==true&&Cross[9]==true)||(Cross[3]==true&&Cross[5]==true&&Cross[7]==true))

{
    // GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Cyan, TEXT("Cross win"));
    WinUI();
    // if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(GetHUD()))
    // {
    //     MenuHUD->EndMenu();
    // }
}

else if (GM->DefineTurn == 10)
{
    EqualUI();
}
//   for (int i=0; i<8;i++)
//   {
   
//     if ( Circle[wintarget[i][1]] == true && Circle[wintarget[i][2]] == true && Circle[wintarget[i][3]] == true)
//     {
//         GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Cyan, TEXT("Circle win"));
//     }

//     else if ( Cross[wintarget[i][1]] == true && Cross[wintarget[i][2]] == true && Cross[wintarget[i][3]] == true)

//     {
//         GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Cyan, TEXT("Cross win"));
        
//     }
       
    
//   }

//   GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Cyan, TEXT("Cross win"));
}

void ANewGameMode::WinUI_Implementation()
{

}
void ANewGameMode::EqualUI_Implementation()
{
    
}