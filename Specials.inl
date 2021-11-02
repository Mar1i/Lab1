#include"Specials.h"
template <class T>
void save(T& a, std::string name) {


	std::ofstream fout;
	fout.open(name, std::ofstream::app);
	if (fout.is_open()) {
		T obj = a;
		fout.write((char*)&obj, sizeof(T));
	}
	else {
		std::cout << "file " << name << " not open\n";
	}
	fout.close();

}

template<class T>
inline MyList<T> recovery(T a, std::string name)
{

	std::ifstream fin;
	MyList<T> List;
	fin.open(name);
	if (!fin.is_open()) {

		std::cout << "not open " << name << std::endl;
	}
	else {
		int i = 0;
		T obj;
		while (fin.read((char*)&obj, sizeof(T))) {
			std::cout << "[" << i << "]:" << std::endl;
			cout << obj;
			List.append(T(obj));
			i++;
		}
		std::cout << std::endl;
	}
	fin.close();
	return MyList<T>(List);

}