#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "7 Лабораторная работа. Вопрос 1." << endl;

    // 1. Попросите пользователя ввести строку и запишите её в 
    // переменную.

    string myStr;
    cout << "Введите строку состоящую более чем из 4-х символов : ";
    getline(cin, myStr); // для сохранения втрок с пробелами

    // 2. Выведите в консоли подстроку из строки от пользователя 
    // от 2 - го символа до 4 - го символа включительно.

    if (myStr.length() < 4) cout << "Ошибка: Длина строки менее 4-х символов.";
    else cout << myStr.substr(1, 3) << endl;

    // 3. Выведите индекс первого вхождения строки "a" в строку 
    // пользователя, а если вхождения нет, то выведите в консоль: 
    // "Символа 'a' не найдено".

    int firstPosEn = myStr.find("a"); // en
    int firstPosRu = myStr.find("а"); // ru

    if (firstPosEn < 0 && firstPosRu < 0) // огромное условие для отлова RU и EN
        cout << "Символа 'a' не найдено" << endl;
    else if (firstPosEn > 0 && firstPosRu > 0) 
        cout << "Индекс первого вхождения 'a' в строку '" << myStr << "' - " <<
        ((firstPosEn < firstPosRu) ? firstPosEn : firstPosRu) << endl;
    else if (firstPosEn > 0) 
        cout << "Индекс первого вхождения 'a' в строку '" << 
        myStr << "' - " << firstPosEn << endl;
    else 
        cout << "Индекс первого вхождения 'a' в строку '" <<
        myStr << "' - " << firstPosRu << endl;

    cout << "Hello World!" << endl;
}
