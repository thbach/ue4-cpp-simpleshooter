// CP TB 2020


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    HUD->RemoveFromViewport();
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

void AShooterPlayerController::BeginPlay()
{
    Super::BeginPlay();

    HUD = CreateWidget(this, HUDClass);
    if (HUD) HUD->AddToViewport();

}
