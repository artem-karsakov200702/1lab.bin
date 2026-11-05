
#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include "processor.h"

using namespace std;

// Функция вывода заголовка таблицы
inline void printHeader()
{
    cout << left
        << setw(15) << "Производитель"
        << setw(25) << "Модель"
        << setw(12) << "Сокет"
        << setw(8) << "Ядра"
        << setw(10) << "Частота"
        << setw(10) << "Кэш"
        << setw(10) << "Цена"
        << endl;

    cout << "--------------------------------------------------------------------------\n";
}

// Функция вывода одного процессора
inline void printProcessor(Processor p)
{
    cout << left
        << setw(15) << p.brand
        << setw(25) << p.model
        << setw(12) << p.socket
        << setw(8) << p.cores
        << setw(10) << p.frequency
        << setw(10) << p.cache
        << setw(10) << p.price
        << endl;
}

// Функция вывода всех процессоров
inline void showProcessors()
{
    Processor p;

    ifstream file("processors.dat", ios::binary);

    if (!file)
    {
        cout << "\nФайл пока пуст.\n";
        return;
    }

    cout << "\n==================== СПИСОК ПРОЦЕССОРОВ ====================\n";

    printHeader();

    while (file.read((char*)&p, sizeof(p)))
    {
        printProcessor(p);
    }

    file.close();
}

