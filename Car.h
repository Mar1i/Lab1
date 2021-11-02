#pragma once
#include"Carrier.h"
#include"MyList.h"
#include<iostream>
class Car:public Carrier
{
	/*Для автомобиля определено: год выпуска, марка, модель, в какие города 
осуществляется доставка и для каждого города определено количество часов 
доставки, объем груза.*/
	char type[64];
	char model[64];
	int year;
	float volumeCargo;

	struct City
	{
		char name[128];
		char hours[128];
	};
	City ST;
	

public:

	Car();
	Car(int i);
	Car(const Car& obj);
	void set() override;
	Car& operator=(const Car& obj);
	friend ostream& operator<<(std::ostream& out, const Car& other);
	friend istream& operator>> (std::istream& in, Car& other);
};

