#pragma once
#include"Element.h"
#include<stdarg.h>
#include<iostream>
template <class T>
class MyList
{

	int size;
	Element<T>* head;//указатель на голову

public:
	MyList();//конструктор без параметров
	MyList(const MyList<T>& obj);//констркутор копирования
	MyList(T* arr, int size);//конструктор с параметрами 
	MyList(int n,T obj, ...);//коснтруктор с неизместным числом параметров
	~MyList();//деструктор 
	MyList(int a);//создано дня приведдения к типу

	int getSize();
	void append(T obj);
	void irase(int i);
	void save(std::string filename);
	void recovery(std::string filename);

	T& operator[](const int i);//оператор индексации
	MyList<T>& operator=(const MyList<T>&obj);//оператор присвоения
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, const MyList<T>& other);

};

#include"MyList.inl"
