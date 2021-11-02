#pragma once
#include"Carrier.h"
#include"MyList.h"
class Airplane:public Carrier
{
	/*���, ������������, ����� ������������ �����, ��������, 
����� ������ ��������. */
	char type[64];
	char name[64];
	struct Gabarits
	{
		float lenght;
		float wingspan;
		float maxSpeed;
	};
	float volumeCargo;

	Gabarits gb;
	char cities[128];//������ �������

public:

	Airplane();
	Airplane(int i);
	Airplane(const Airplane& obj);
	
	void set() override;
	Airplane& operator=(const Airplane& obj);
	friend ostream& operator<<(std::ostream& out, const Airplane& other);
	friend istream& operator>> (std::istream& in, Airplane& other);
	

};

