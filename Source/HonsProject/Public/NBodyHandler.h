// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GravBody.h"
#include "UObject/ConstructorHelpers.h"
#include <string>
#include "NBodyHandler.generated.h"


UCLASS()
class HONSPROJECT_API ANBodyHandler : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANBodyHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//UI functions
	UFUNCTION(BlueprintCallable, Category = "SimSpeed")
	void raiseSimulationSpeed();
	UFUNCTION(BlueprintCallable, Category = "SimSpeed")
	void lowerSimulationSpeed();
	UFUNCTION(BlueprintCallable, Category = "SimSpeed")
	void pauseSimulation();
	UFUNCTION(BlueprintCallable, Category = "SimCentre")
	void RecentreSimulation();
	UFUNCTION(BlueprintCallable, Category = "SimCentre")
	void doubleAllScales();
	UFUNCTION(BlueprintCallable, Category = "ClearSim")
	void ClearSimulation();
	UFUNCTION(BlueprintCallable, Category = "ClearSim")
	void flipPlanetNames();

	//array holding a reference to all bodies
	TArray<AGravBody*> myGravBodies;


	//spawning
	void spawnBodyAt(FVector position_, FVector velocity_, double mass_, std::string name_ = "GravBody", float radius_ = 0.0f, FVector4 colour_ = FVector4(0.0f,0.0f,0.0f,0.0f));
	void spawnSolarSystem();
	void graduallySpawnBodies(int spawnsPerFrame = 1);


	//direct integration of gravitational calculations
	void calculateAllVelocityChanges(double dt);


	//UI variables
	UPROPERTY(Category = "forUI", BlueprintReadWrite)
	float timeMultiplier = 1.0f;
	UPROPERTY(Category = "forUI", BlueprintReadWrite)
	float SimulationElapsedTime = 0.0f;
	UPROPERTY(Category = "forUI", BlueprintReadWrite)
	int BodiesInSimulation = 0;


	//simulation dependant variables
	UPROPERTY(Category = "SimulationRelevant", EditAnywhere, BlueprintReadWrite)
	int bodiesToSpawn = 20;
	UPROPERTY(Category = "SimulationRelevant", EditAnywhere, BlueprintReadWrite)
	int SpawnsPerFrame = 5;
	UPROPERTY(Category = "SimulationRelevant", EditAnywhere, BlueprintReadWrite)
	FVector InitialSpawnCentre = FVector(0,0,0);
	UPROPERTY(Category = "SimulationRelevant", EditAnywhere, BlueprintReadWrite)
	float SpawnLocationBounds = 10;
	UPROPERTY(Category = "SimulationRelevant", EditAnywhere, BlueprintReadWrite)
	float SpawnInitialMaxSpeed = 3;
	UPROPERTY(Category = "SimulationRelevant", EditAnywhere, BlueprintReadWrite)
	float SpawnInitialMaxMass = 5;
	UPROPERTY(Category = "SimulationRelevant", EditAnywhere, BlueprintReadWrite)
	bool shouldSpawnSolarSystem = false;
	UPROPERTY(Category = "SimulationRelevant", EditAnywhere, BlueprintReadWrite)
	bool showPlanetNames = false;
	UPROPERTY(Category = "SimulationRelevant", EditAnywhere, BlueprintReadWrite)
	int SolarPlanetToSpawn = 0;//0-7 to spawn a specific planet+ sun,anything else for all of them


	//double bigG = 0.000000000066743f; //when using kg,m and s
	double bigG = 39.4784f; //when using SolarMass, AU and Years
	bool notPaused = false;
	int gradualSpawnerIndex = 0;
	bool spawningBodies = true;
	
};
