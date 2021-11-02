#include "Keeper.h"
#include"Specials.h"
Keeper::Keeper()
{
	Car ca;
	std::cout << "-------------------Cars--------------------\n";
	Cars = recovery(ca, "car");

	Airplane air;
	std::cout << "-----------------Airplanes-----------------\n";
	Airplanes = recovery(air, "air");

	Train tr;
	std::cout << "------------------Trains-------------------\n";
	Trains = recovery(tr, "trains");
}

void Keeper::print()
{
	this->printAir();
	this->printCar();
	this->printTrain();
}

void Keeper::printAir()
{
	cout << Airplanes;
}

void Keeper::printCar()
{
	cout << Cars;
}

void Keeper::printTrain()
{
	cout << Trains;
}

void Keeper::chageAirplanes()
{
	int i;
	cout << Airplanes;
	cout << "Change item: ";
	cin >> i;
	Airplanes[i].set();
	saves();

}

void Keeper::chageCars()
{
	int i;
	cout << Cars;
	cout << "Change item: ";
	cin >> i;
	Cars[i].set();
	saves();
}

void Keeper::changeTrain()
{
	int i;
	cout << Trains;
	cout << "Change item: ";
	cin >> i;
	Trains[i].set();
	saves();
}

void Keeper::addAirs()
{
	
	Airplanes.append(Airplane(1));
	saves();

}

void Keeper::addCar()
{
	Cars.append(Car(1));
	saves();
}

void Keeper::addTrain()
{
	Trains.append(Train(1));
	saves();
}

void Keeper::saves()
{

	std::string path = "air";
	ofstream of;
	of.open(path);
	of.close();
	for (int i = 0; i < Airplanes.getSize(); i++) {
		cout << Airplanes[i];
		save(Airplanes[i], path);
	}

	path = "car";
	of.open(path);
	of.close();

	for (int i = 0; i < Cars.getSize(); i++) {

		save(Cars[i], path);
	}

	path = "trains";
	of.open(path);
	of.close();
	for (int i = 0; i < Trains.getSize(); i++) {

		save(Cars[i], path);
	}


}

void Keeper::deAir()
{
	int i;
	cout << Airplanes;
	cout << "Change item: ";
	cin >> i;
	Airplanes.irase(i);
	saves();

}

void Keeper::deCar()
{
	int i;
	cout << Cars;
	cout << "Change item: ";
	cin >> i;
	Cars.irase(i);
	saves();
}

void Keeper::deTrain()
{
	int i;
	cout << Trains;
	cout << "Change item: ";
	cin >> i;
	Trains.irase(i);
	saves();
}

int Keeper::getCntAir()
{
	return Airplanes.getSize();
}

int Keeper::getCntCar()
{
	return Cars.getSize();
}

int Keeper::gerCntTrain()
{
	return Trains.getSize();
}
