#pragma once
#include<string>
#include<fstream>
#include"MyList.h"
template <class T>
void save(T& a, std::string name);

template<class T>
inline MyList<T> recovery(T a, std::string name);

#include"Specials.inl"