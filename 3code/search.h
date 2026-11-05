
#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include "processor.h"
#include "output.h"

using namespace std;

// Функция поиска процессоров
inline void searchProcessor()
{
    Processor p;

    ifstream file("processors.dat", ios::binary);

    if (!file)
    {
        cout << "\nФайл пока пуст.\n";
        return;
    }

    int searchChoice;

    cout << "\n========== ПОИСК ==========\n";
    cout << "1. Производитель\n";
    cout << "2. Модель\n";
    cout << "3. Сокет\n";
    cout << "4. Количество ядер\n";
    cout << "5. Частота\n";
    cout << "6. Кэш\n";
    cout << "7. Цена\n";
    cout << "===========================\n";
    cout << "Выберите поле: ";
    cin >> searchChoice;

    bool found = false;

    // Поиск по строковым полям
    if (searchChoice >= 1 && searchChoice <= 3)
    {
        char text[30];

        cout << "Введите текст для поиска: ";
        cin.ignore();
        cin.getline(text, 30);

        cout << "\nРезультат поиска:\n";
        printHeader();

        while (file.read((char*)&p, sizeof(p)))
        {
            bool result = false;

            if (searchChoice == 1)
                result = (strstr(p.brand, text) != NULL);

            if (searchChoice == 2)
                result = (strstr(p.model, text) != NULL);

            if (searchChoice == 3)
                result = (strstr(p.socket, text) != NULL);

            if (result)
            {
                found = true;
                printProcessor(p);
            }
        }
    }

    // Поиск по числовым полям
    else if (searchChoice >= 4 && searchChoice <= 7)
    {
        double minValue;
        double maxValue;

        cout << "Введите минимальное значение: ";
        cin >> minValue;

        cout << "Введите максимальное значение: ";
        cin >> maxValue;

        cout << "\nРезультат поиска:\n";
        printHeader();

        while (file.read((char*)&p, sizeof(p)))
        {
            double value = 0;

            if (searchChoice == 4)
                value = p.cores;

            if (searchChoice == 5)
                value = p.frequency;

            if (searchChoice == 6)
                value = p.cache;

            if (searchChoice == 7)
                value = p.price;

            if (value >= minValue && value <= maxValue)
            {
                found = true;
                printProcessor(p);
            }
        }
    }
    else
    {
        cout << "\nНеверный пункт поиска!\n";
        file.close();
        return;
    }

    if (!found)
    {
        cout << "\nНичего не найдено.\n";
    }

    file.close();
}

