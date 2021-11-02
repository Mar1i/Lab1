#pragma once
#include"Element.h"
#include<stdarg.h>
#include<iostream>
template <class T>
class MyList
{

	int size;
	Element<T>* head;//��������� �� ������

public:
	MyList();//����������� ��� ����������
	MyList(const MyList<T>& obj);//����������� �����������
	MyList(T* arr, int size);//����������� � ����������� 
	MyList(int n,T obj, ...);//����������� � ����������� ������ ����������
	~MyList();//���������� 
	MyList(int a);//������� ��� ����������� � ����

	int getSize();
	void append(T obj);
	void irase(int i);
	void save(std::string filename);
	void recovery(std::string filename);

	T& operator[](const int i);//�������� ����������
	MyList<T>& operator=(const MyList<T>&obj);//�������� ����������
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, const MyList<T>& other);

};

#include"MyList.inl"
