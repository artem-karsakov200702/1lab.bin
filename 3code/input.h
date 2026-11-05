
#pragma once

#include <iostream>
#include <fstream>
#include "processor.h"

using namespace std;

// Функция добавления процессора
inline void addProcessor()
{
    Processor p;

    ofstream file("processors.dat", ios::binary | ios::app);

    if (!file)
    {
        cout << "Ошибка открытия файла!\n";
        return;
    }

    cout << "\n--- Ввод данных ---\n";

    cout << "Производитель: ";
    cin.ignore();
    cin.getline(p.brand, 20);

    cout << "Модель: ";
    cin.getline(p.model, 30);

    cout << "Сокет: ";
    cin.getline(p.socket, 15);

    cout << "Количество ядер: ";
    cin >> p.cores;

    cout << "Частота (ГГц): ";
    cin >> p.frequency;

    cout << "Кэш (МБ): ";
    cin >> p.cache;

    cout << "Цена: ";
    cin >> p.price;

    file.write((char*)&p, sizeof(p));

    file.close();

    cout << "\nДанные успешно добавлены!\n";
}

