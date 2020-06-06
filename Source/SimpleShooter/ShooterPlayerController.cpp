// CP TB 2020


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner) 
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    
    UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
    if (bIsWinner && WinScreen)
    {
        WinScreen->AddToViewport();
    }

    UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
    if (!bIsWinner && LoseScreen)
    {
        LoseScreen->AddToViewport();
    }

    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
