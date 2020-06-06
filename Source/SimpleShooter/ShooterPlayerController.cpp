// CP TB 2020


#include "ShooterPlayerController.h"
#include "TimerManager.h"


void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner) 
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);


    UE_LOG(LogTemp, Warning, TEXT("GAME HAS ENDED"));  
}
