#include "Airplane.h"
#include<iostream>


Airplane::Airplane()
{
	this->type[0] = '\0';
	this->name[0] = '\0';
	this->gb.lenght = 0;
	this->volumeCargo = 0;
	this->gb.maxSpeed = 0;
	this->gb.wingspan = 0;
	this->cities[0] = '\0';
}

Airplane::Airplane(int i)
{
 	this->set();
}

Airplane::Airplane(const Airplane& obj)
{
	int i = 0;
	while (obj.type[i] != '\0') {
		this->type[i] = obj.type[i];
		i++;
	}
	this->type[i] = '\0';

	i = 0;
	while (obj.name[i] != '\0') {
		this->name[i] = obj.name[i];
		i++;
	}
	this->name[i] = '\0';

	this->gb.lenght = obj.gb.lenght;
	this->gb.wingspan = obj.gb.wingspan;
	this->gb.maxSpeed = obj.gb.maxSpeed;


	this->volumeCargo = obj.volumeCargo;


	i = 0;
	while (obj.cities[i] != '\0') {
		this->cities[i] = obj.cities[i];
		i++;
	}
	this->cities[i] = '\0';


}

void Airplane::set()
{

	string str = "";
	cout << "type: ";
	cin >>str;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter string" <<  " - ";
		cin >> str;
	}
	int i = 0;
	while (i <= str.size()) {
		this->type[i] = str[i];
		i++;
	}
	this->type[i] = '\0';

	cout << "name: ";
	cin >> str;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter string" << " - ";
		cin >> str;
	}
	i = 0;
	while (i <= str.size()) {
		this->name[i] = str[i];
		i++;
	}
	this->name[i] = '\0';
	

	cout << "lenght: ";
	cin >>this->gb.lenght;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter float" << " - ";
		cin >>this->gb.lenght;
	}
	

	cout << "wingspain: ";
	cin>>this->gb.wingspan;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter float" << " - ";
		cin >> this->gb.wingspan;
	}


	cout << "max speed: ";
	cin>>this->gb.maxSpeed;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter float" << " - ";
		cin >> this->gb.maxSpeed;
	}
	

	cout << "volume cargo: ";
	cin>>this->volumeCargo;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter float" << " - ";
		cin >> this->volumeCargo;
	}


	cout << "Cities: ";
	cin >> str;
	//getline(cin,str);
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter string" << " - ";
		cin >> str;
	}
	i = 0;
	while (i <= str.size()) {
		this->cities[i] = str[i];
		i++;
	}
	this->cities[i] = '\0';


}

Airplane& Airplane::operator=(const Airplane& obj)
{
	int i = 0;
	while (obj.type[i] != '\0') {
		this->type[i] = obj.type[i];
		i++;
	}
	this->type[i] = obj.type[i];

	i = 0;
	while (obj.name[i] != '\0') {
		this->name[i] = obj.name[i];
		i++;
	}
	this->name[i] = obj.name[i];

	this->gb.lenght = obj.gb.lenght;
	this->gb.wingspan = obj.gb.wingspan;
	this->gb.maxSpeed = obj.gb.maxSpeed;
	this->volumeCargo = obj.volumeCargo;


	i = 0;
	while (obj.cities[i] != '\0') {
		this->cities[i] = obj.cities[i];
		i++;
	}
	this->cities[i] = obj.cities[i];

	return *this;

}

ostream& operator<<(std::ostream& out, const Airplane& other)
{
	return out << other.type << "\t" << other.name << "\t" <<
		other.volumeCargo << "\t" << other.gb.lenght << "\t"<<other.gb.wingspan << "\t" << other.gb.maxSpeed <<
		"\t" << other.cities << "\n";
}

istream& operator>>(std::istream& in, Airplane& other)
{
	cout << "type: ";
	in >> other.type;

	cout << "name: ";
	in >> other.name;

	cout << "lenght: ";
	in >> other.gb.lenght;

	cout << "wingspain: ";
	in >> other.gb.wingspan;

	cout << "max speed: ";
	in >> other.gb.maxSpeed;

	cout << "volume cargo: ";
	in >> other.volumeCargo;

	cout << "Cities: ";
	in >> other.cities;
	return in;
}
