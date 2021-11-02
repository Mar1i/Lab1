#pragma once
#include"MyList.h"
#include"Airplane.h"
#include"Car.h"
#include"Train.h"

class Keeper
{
	MyList<Airplane> Airplanes;
	MyList<Car> Cars;
	MyList<Train> Trains;

public:
	Keeper();
	void print();
	void printAir();
	void printCar();
	void printTrain();
	
	void chageAirplanes();
	void chageCars();
	void changeTrain();

	void addAirs();
	void addCar();
	void addTrain();

	void saves();

	void deAir();
	void deCar();
	void deTrain();

	int getCntAir();
	int getCntCar();
	int gerCntTrain();

};

