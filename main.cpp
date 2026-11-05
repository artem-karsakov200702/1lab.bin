#include <iostream>
#include <clocale>
#include <windows.h>

#include "processor.h"
#include "input.h"
#include "output.h"
#include "search.h"

using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    setlocale(LC_ALL, "Russian");

    int choice;

    do
    {
        cout << "\n========== КАТАЛОГ ПРОЦЕССОРОВ ==========\n";
        cout << "1. Ввод данных\n";
        cout << "2. Вывод данных\n";
        cout << "3. Поиск\n";
        cout << "4. Выход\n";
        cout << "==========================================\n";
        cout << "Ваш выбор: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            addProcessor();
            break;

        case 2:
            showProcessors();
            break;

        case 3:
            searchProcessor();
            break;

        case 4:
            cout << "\nПрограмма завершена.\n";
            break;

        default:
            cout << "\nНеверный пункт меню!\n";
            break;
        }

    } while (choice != 4);

    return 0;
}
