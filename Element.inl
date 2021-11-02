#include"Element.h"

template <class T>
Element<T>* Element<T>::getAdress() {
	return adress;
}

template<class T>
inline Element<T>::Element()
{
	this->adress = nullptr;
	
}

template<class T>
inline Element<T>::Element(Element<T>* ptr, T data)
{
	this->adress = ptr;
	this->data = data;
}



template <class T>
T& Element<T>::getVal() {
	return data;
}

template <class T>
void Element<T>::setAdr(Element<T>* adress) {
	this->adress = adress;
}

template <class T>
void Element<T>::setVal(T& val) {
	this->data = val;
}
