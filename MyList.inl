#include"MyList.h"
#include<string>
#include<fstream>
using namespace std;
template<class T>
inline MyList<T>::MyList()
{
	std::cout << "¬ызван конструктор без параметров "  << "по адресу "<<
		this << "\n";
	head = nullptr;
	size = 0;

}

template<class T>
inline MyList<T>::MyList(const MyList<T>& obj)
{
	std::cout << "¬ызван конструктор копировани€ класса "<< "по адресу "<<
		this << "\n";
	this->head = nullptr;
	this->size = 0;
	Element<T>* ptr = this->head, *objPtr = obj.head;
	
	for (int i = 0; i < obj.size; i++) {
		Element<T>* element = new(Element<T>);
		if (size == 0) {

			element->setVal(objPtr->getVal());
			element->setAdr(element);
			this->head = element;

		}

		else {
			Element<T>* ptr = head;
			while (ptr->getAdress() != head)//к  последнему пришли
				ptr = ptr->getAdress();
			element->setVal(objPtr->getVal());
			ptr->setAdr(element);
			element->setAdr(head);
		}

		this->size++;
	}
}

template<class T>
inline MyList<T>::MyList(T* arr, int size)
{
	std::cout << "¬ызван конструктор класса с параметрами массив и размер массива"  << "по адресу "<<
		this << "\n";
	this->head = nullptr;
	this->size = 0;
	for (int i = 0; i < size; i++) {
		this->append(arr[i]);
	}
}

template<class T>
inline MyList<T>::MyList(int n,T obj, ...):head(nullptr),size(0)
{
	
	std::cout << "¬ызван конструктор класса с неограниченным числом параметров "  << "по адресу "<<
		this << "\n";
	va_list argptr;

	va_start(argptr, obj);            //--инициализаци€ указател€
	T k = obj;//--промежуточна€ переменна€ 
	int sizeN = n;
	do {
		if (this->size == sizeN)
			break;
		
		Element<T>* element = new(Element<T>);
		if (size == 0) {

			element->setVal(k);
			element->setAdr(element);
			this->head = element;

		}

		else {
			Element<T>* ptr = head;
			while (ptr->getAdress() != head)//к  последнему пришли
				ptr = ptr->getAdress();
			element->setVal(k);
			ptr->setAdr(element);
			element->setAdr(head);
		}

		this->size++;
		//sizeN++;
	} while (k = va_arg(argptr, T));     //--пока не ноль -передвигаемс€
	va_end(argptr);
}

template<class T>
inline MyList<T>::~MyList()
{
	std::cout << "¬ызван деструктор класса " << "по адресу "<<
		this<<"\n";
	try
	{
		if (size <= 0)
			throw "Empty list";
		
		Element<T>* hptr=head, *elptr=head;
		
		while (elptr->getAdress() != head)
			elptr = elptr->getAdress();
		
		//elptr указывает на последний элемент 

		for (int i = 0; i < this->size; i++) {
			if (head != elptr) {

				hptr = this->head->getAdress();
				delete this->head;
				this->head = hptr;

			}
			else {
				delete head;
			}

		}
		size = 0;


	}
	catch (const char* exception)
	{
		std::cout << exception<<"\n";
	}
}

template<class T>
inline MyList<T>::MyList(int a)
{
	for (int i = 0; i < this->size; i++)
		this->irase(i);
	for (int i = 0; i < a; i++)
		this->append(0);
}

template<class T>
inline int MyList<T>::getSize()
{
	return this->size;
}

template<class T>
inline void MyList<T>::append(T obj)
{
	
	Element<T>* element = new(Element<T>);
	if (size == 0) {
	
		element->setVal(obj);
		element->setAdr(element);
		this->head = element;
	
	}

	else {
		Element<T>* ptr = head;
		while (ptr->getAdress()!=head)//к  последнему пришли
			ptr = ptr->getAdress();
		element->setVal(obj);
		ptr->setAdr(element);
		element->setAdr(head);
	}

	this->size++;

}

template<class T>
inline void MyList<T>::irase(int i)
{
	try
	{
		int thisIndex = i;
		if (i > this->size||i<0)
			throw "Index can'be begger than size or less 0";
		else if (i == this->size)
			thisIndex--;

		Element<T>* lastptr = head, *elptr = head,*preIelement = head;
		while (lastptr->getAdress()!= head) 	
			lastptr = lastptr->getAdress();
		
		if (thisIndex == 0) {
			elptr = elptr->getAdress();
			lastptr->setAdr(elptr);
			delete head;
			head = elptr;
		}
		else if (thisIndex < this->size - 1) {

			for (int i = 0; i < thisIndex; i++) {
				if (i == thisIndex - 1) {
					preIelement = elptr;
					elptr = elptr->getAdress();
				}
				else {
					elptr = elptr->getAdress();
				}
			}
			preIelement->setAdr(elptr->getAdress());
			delete elptr;
			
		}
		else if(thisIndex == this->size - 1) {
			while (elptr->getAdress()->getAdress() != head)
				elptr = elptr->getAdress();
			elptr->setAdr(head);
			delete lastptr;
			

		}
		this->size--;
		
	}
	catch (const char* exception)
	{
		std::cout << exception << "\n";
	}
	
}

template<class T>
inline void MyList<T>::save(std::string filename)
{
	string path = filename;
	ofstream fout;
	fout.open(path, ofstream::app);
	if (!fout.is_open()) {
		std::cout << "file wasn't opened\n";
	}
	else {
		std::cout << "file was open\n";
		
		for(int i = 0;i<this->size;i++)
		
			fout.write((char*)&operator[](i), sizeof(T));
	}
	fout.close();

}

template<class T>
inline void MyList<T>::recovery(std::string filename)
{
	ifstream fin;
	//MyList<T> List;
	fin.open(filename);
	if (!fin.is_open()) {

		std::cout << "not open " << filename << std::endl;
	}
	else {
		int i = 0;
		T obj;
		while (fin.read((char*)&obj, sizeof(T))) {
			this->append(obj);
			//i++;
		}
		//std::cout << std::endl;
	}
	fin.close();
	

	//return MyList<T>(List);
}


template<class T>
inline T& MyList<T>::operator[](const int index)
{
	int thisIndex = index;
	try {
		if (thisIndex > this->size)
			throw "Index bigger than size";
		else if (thisIndex < 0)
			throw "Index can't be less than 0";
		else if (thisIndex == this->size)
			thisIndex--;

		Element<T>* ptr = head;
		for (int i = 0; i < index; i++) {
			ptr = ptr->getAdress();
		}
		return ptr->getVal();
	}
	
	catch (const char* exception)
	{
		std::cout << exception << "\n";
	}
}

template<class T>
inline MyList<T>& MyList<T>::operator=(const MyList<T>&obj)
{

	for (int i = 0; i < this->size; i++)
		this->irase(0);

	if (obj.size == 0)
		return *this;
	
	Element<T>* objPtr = obj.head;
	for (int i = 0; i < obj.size; i++) {
		this->append(objPtr->getVal());
		objPtr = objPtr->getAdress();
	}

	return *this;


}

template<class T>
inline std::ostream& operator<<(std::ostream& out, const MyList<T>& other) {
	Element<T>* ptr = other.head;
	for (int i = 0; i < other.size; i++) {
		out << "[" << i << "]\n";
		out << ptr->getVal() << "\n";
		ptr = ptr->getAdress();
		
	}
	out << "\n";


	return out;
}

