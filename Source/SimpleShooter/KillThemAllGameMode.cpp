// CP TB 2020


#include "KillThemAllGameMode.h"


void AKillThemAllGameMode::PawnKilled(APawn* PawnKilled) 
{
    Super::PawnKilled(PawnKilled);

    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());

    if (PlayerController) 
    {
        PlayerController->GameHasEnded(nullptr, false);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("one pawn got killed"));    
}
    