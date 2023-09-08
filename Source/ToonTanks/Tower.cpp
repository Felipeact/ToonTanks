// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"


void ATower::Tick(float DeltaTme) 
{
    Super::Tick(DeltaTme);

    if (Tank)
    {
        //Find the dist to the tnk
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
        //Check if tank is in range 
        if ( Distance <= FireRange)
        {
            //if in ranfe rotate turret towards tank
            RotateTurret(Tank->GetActorLocation());
        }
    }



}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

}