// IbragimovLaba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*Класс Грузоперевозчик хранит данные о самолетах, поездах, автомобилях. Для 
самолета определено: тип, наименование, объем перевозимого груза, габариты, 
какие города посещает. Для поезда определено: наименование, год выпуска, 
полный маршрут следования, количество вагонов, объем перевозимого груза. 
Для автомобиля определено: год выпуска, марка, модель, в какие города 
осуществляется доставка и для каждого города определено количество часов 
доставки, объем груза.*/
#include <iostream>
#include"MyList.h"
#include"Specials.h"
#include"Keeper.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    bool flagFirst = true;
    bool flagSecond = true;
    Keeper Container;
    while (flagFirst) {
        int i;
        cout << "-----------MENU--------------\n";
        cout << "1. Показать списки транспорта\n";
        cout << "2. Меню самолётов\n";
        cout << "3. Меню машин\n";
        cout << "4. Меню поездов\n";
        cout << "5. Выход\n";
        cout << "вы выбрали - ";
        cin >> i;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();

            cout << "Enter int" << " - ";
            cin >> i;
        }
        switch (i)
        {
        case 1:
            Container.print();
            break;
        case 2:
            flagSecond = true;
            while (flagSecond)
            {
                int j;
                cout << "Сейчас самолётов - " << Container.getCntAir() << endl;
                cout << "1. Показать самолёты\n";
                cout << "2. Добавить самолёт\n";
                cout << "3. Удалить самолёт\n";
                cout << "4. Изменить данные самолёта\n";
                cout << "5. Выйти в меню\n";
                cout << "вы выбрали - ";
                cin >> j;

                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();

                    cout << "Enter int" << " - ";
                    cin >> j;
                }
                switch (j)
                {
                case 1:
                    Container.printAir();
                    break;
                case 2:
                    Container.addAirs();
                    break;
                case 3:
                    Container.deAir();
                    break;
                case 4:
                    Container.chageAirplanes();
                    break;
                default:
                    flagSecond = false;
                    break;
                }
            }
            break;
        case 3:
            flagSecond = true;
            while (flagSecond)
            {
                int j;
                cout << "Сейчас машин - " << Container.getCntCar() << endl;
                cout << "1. Показать машины\n";
                cout << "2. Добавить машину\n";
                cout << "3. Удалить машину\n";
                cout << "4. Изменить данные машины\n";
                cout << "5. Выйти в меню\n";
                cout << "вы выбрали - ";
                cin >> j;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();

                    cout << "Enter int" << " - ";
                    cin >> j;
                }
                switch (j)
                {
                case 1:
                    Container.printCar();
                    break;
                case 2:
                    Container.addCar();
                    break;
                case 3:
                    Container.deCar();
                    break;
                case 4:
                    Container.chageCars();
                    break;
                default:
                    flagSecond = false;
                    break;
                }
            }
            break;
        
        case 4:
            flagSecond = true;
            while (flagSecond)
            {
                int j;
                cout << "Сейчас поездов - " << Container.getCntAir() << endl;
                cout << "1. Показать поезда\n";
                cout << "2. Добавить поезд\n";
                cout << "3. Удалить поезд\n";
                cout << "4. Изменить данные поезда\n";
                cout << "5. Выйти в меню\n";
                cout << "вы выбрали - ";
                cin >> j;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();

                    cout << "Enter int" << " - ";
                    cin >> j;
                }
                switch (j)
                {
                case 1:
                    Container.printAir();
                    break;
                case 2:
                    Container.addAirs();
                    break;
                case 3:
                    Container.deAir();
                    break;
                case 4:
                    Container.chageAirplanes();
                    break;
                default:
                    flagSecond = false;
                    break;
                }
            }
            break;
        default:
            flagFirst = false;
            break;
        }
    
    }    

    return 0;
}


   