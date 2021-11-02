#include "Car.h"


Car::Car()
{
	this->type[0] = '\0';
	this->model[0] = '\0';
	this->year = 0;
	this->volumeCargo =0;
	this->ST.name[0] = '\0';
	this->ST.hours[0] = '\0';
}

Car::Car(int i)
{
	this->set();
}

Car::Car(const Car& obj)
{
	int i = 0;
	while (obj.type[i] != '\0') {
		this->type[i] = obj.type[i];
		i++;
	}	
	this->type[i] = obj.type[i];

	i = 0;
	while (obj.model[i] != '\0') {
		this->model[i] = obj.model[i];
		i++;
	}
	this->model[i] = obj.model[i];

	this->year = obj.year;
	this->volumeCargo = obj.volumeCargo;


	i = 0;
	while (obj.model[i] != '\0') {
		this->ST.name[i] = obj.ST.name[i];
		i++;
	}
	this->ST.name[i] = obj.ST.name[i];

	i = 0;
	while (obj.model[i] != '\0') {
		this->ST.hours[i] = obj.ST.hours[i];
		i++;
	}
	this->ST.hours[i] = obj.ST.hours[i];
}

void Car::set()
{
	string str="";

	cout << "type: ";
	cin>>str;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter string" << " - ";
		cin >> str;
	}
	int i = 0;
	while (i <= str.size()) {
		this->type[i] = str[i];
		i++;
	}
	this->type[i] = str[i];

	cout << "model: ";
	cin>>str;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter float" << " - ";
		cin >> this->model;
	}
	i = 0;
	while (i <= str.size()) {
		this->model[i] = str[i];
		i++;
	}
	this->model[i] = '\0';
	
	cout << "year: ";
	cin >> this->year;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter int" << " - ";
		cin >> this->year;
	}



	cout << "volume cargo: ";
	cin >> this->volumeCargo;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter float" << " - ";
		cin >> this->volumeCargo;
	}


	cout << "Cities: ";
	cin >> str;
	//getline(cin, str);
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter string" << " - ";
		cin >> str;
	}
	i = 0;
	while (i <= str.size()) {
		this->ST.name[i] = str[i];
		i++;
	}
	this->ST.name[i] = '\0';


	cout << "Enter hours: ";
	cin >> str;
	//getline(cin, str);
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter string" << " - ";
		cin >> str;
	}
	while (i <= str.size()) {
		this->ST.hours[i] = str[i];
		i++;
	}
	this->ST.hours[i] = '\0';

}

Car& Car::operator=(const Car& obj)
{	
	int i =0;
	while (obj.type[i]!='\0') {
		this->type[i] = obj.type[i];
		i++;
	}
	this->type[i] = obj.type[i];

	i = 0;
	while (obj.model[i] != '\0') {
		this->model[i] = obj.model[i];
		i++;
	}
	this->model[i] = obj.model[i];

	this->year = obj.year;
	this->volumeCargo = obj.volumeCargo;


	i = 0;
	while (obj.model[i] != '\0') {
		this->ST.name[i] = obj.ST.name[i];
		i++;
	}
	this->ST.name[i] = obj.ST.name[i];
	
	i = 0;
	while (obj.model[i] != '\0') {
		this->ST.hours[i] = obj.ST.hours[i];
		i++;
	}
	this->ST.hours[i] = obj.ST.hours[i];


	return *this;
}

ostream& operator<<(std::ostream& out, const Car& other)
{
	return out << other.type << "\t" << other.model << "\t" << other.year << "\t" <<
		other.volumeCargo << "\t" << other.ST.name << other.ST.hours<<"\n";
}

istream& operator>> (std::istream& in, Car& other)
{
	cout << "type: ";
	in >> other.type;
	
	cout << "model: ";
	in >> other.model;

	cout << "year: ";
	in >> other.year;

	cout << "volume cargo: ";
	in >> other.volumeCargo;

	cout << "Cities: ";
	in >> other.ST.name;

	cout << "Enter hours: ";
	in >> other.ST.hours;
	return in;
}
