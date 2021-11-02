#pragma once

template<class T>
class Element
{

private:
	Element<T>* adress;
	T data;

public:

	Element();
	Element(Element<T>* ptr, T data);

	//void save(std::string filename);

	T& getVal();
	Element<T>* getAdress();

	void setVal(T& val);
	void setAdr(Element<T>* adr);

};

#include "Element.inl"
