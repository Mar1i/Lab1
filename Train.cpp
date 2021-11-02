#include "Train.h"

Train::Train()
{
	this->type[0] = '\0';
	this->year = 0;
	this->cntVagons = 0;
	this->volumeCargo = 0;
	this->cities[0] = '\0';
}

Train::Train(int i)
{
	this->set();
}

Train::Train(const Train& obj)
{
	int i = 0;
	while (obj.type[i] != '\0') {
		this->type[i] = obj.type[i];
		i++;
	}
	this->type[i] = obj.type[i];

	this->year = obj.year;
	this->volumeCargo = obj.volumeCargo;
	this->cntVagons = obj.cntVagons;


	i = 0;
	while (obj.cities[i] != '\0') {
		this->cities[i] = obj.cities[i];
		i++;
	}
	this->cities[i] = obj.cities[i];
	
}

void Train::set()
{
	string str="";
	cout << "type: ";
	cin>>str;
	int i = 0;
	while (i <= str.size()) {
		this->type[i] = str[i];
		i++;
	}
	this->type[i] = '\0';

	cout << "year: ";
	cin>>this->year;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter int" << " - ";
		cin >> this->year;
	}
	

	cout << "count of vagons: ";
	cin >> this->cntVagons;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter int" << " - ";
		cin >> this->cntVagons;
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
		this->cities[i] = str[i];
		i++;
	}
	this->cities[i] = '\0';

	
}

Train& Train::operator=(const Train& obj)
{
	int i = 0;
	while (obj.type[i] != '\0') {
		this->type[i] = obj.type[i];
		i++;
	}
	this->type[i] = obj.type[i];

	this->year = obj.year;
	this->volumeCargo = obj.volumeCargo;
	this->cntVagons = obj.cntVagons;


	i = 0;
	while (obj.cities[i] != '\0') {
		this->cities[i] = obj.cities[i];
		i++;
	}
	this->cities[i] = obj.cities[i];

	return *this;
}

ostream& operator<<(std::ostream& out, const Train& other)
{
	return out << other.type << "\t" << other.year << "\t" <<
		other.cntVagons << "\t" << other.volumeCargo << other.cities<< "\t" << 
		"\t" << other.cities << "\n";
}

istream& operator>>(std::istream& in, Train& other)
{
	cout << "type: ";
	in >> other.type;

	cout << "year: ";
	in >> other.year;

	cout << "count of vagons: ";
	in >> other.cntVagons;

	cout << "volume cargo: ";
	in >> other.volumeCargo;

	cout << "Cities: ";
	in >> other.cities;
	return in;
}
