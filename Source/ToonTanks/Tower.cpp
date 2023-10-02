// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"


void ATower::Tick(float DeltaTme) 
{
    Super::Tick(DeltaTme);

    if (InFireRange())
    {
        //if in ranfe rotate turret towards tank
        RotateTurret(Tank->GetActorLocation());
    }



}

void ATower::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);

}

void ATower::CheckFireCondition()
{   
    if ( Tank == nullptr) 
    {
        return;
    }
    
    if (InFireRange() && Tank->bAlive )
    {
        Fire();
    }
}

bool ATower::InFireRange()
{
    if (Tank)
    {
        //Find the dist to the tnk
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

        if ( Distance <= FireRange)
        {
            return true;
        }
    }

    return false;
}