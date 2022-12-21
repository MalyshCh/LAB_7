#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "7 Лабораторная работа. Вопрос 3." << endl;

    // 1. Попросите пользователя ввести радиус окружности.

    float radius;
    cout << "Введите радиус окружности = ";
    cin >> radius;

    // 2. Выведите в консоль длину окружности (длина окружности 
    // считается по формуле : S = 2 * π * r).

    float circumference = 2 * M_PI * radius;
    cout << endl << "Длина окружности = " << circumference << endl;

    // 3. Округлите полученный результат до 3-х знаков после 
    // запятой и выведите его в консоль.

    circumference = trunc(circumference * 1000 + 0.5) / 1000;
    cout << "Длина окружности = " << circumference << endl;

    // 4. Попросите пользователя ввести произвольную строку.

    cin.clear();
    while (cin.get() != '\n');
    string myStr;
    fstream myfile;

    while (true) {
        cout << "Введите произвольую строку : ";
        getline(cin, myStr);

        if (myStr == "exit") break; //7.3.8
        else if (myStr == "read") { // 7.3.6
            cout << "--- файл --- myfile.txt --- начало ---"  << endl;
            myfile.open("myfile.txt", ios::in);
            while (getline(myfile, myStr)) {
                cout << myStr << endl;
            }
            myfile.close();
            cout << "--- файл --- myfile.txt --- конец ---" << endl;
        }
        else if (myStr == "erase") { // 7.3.7
            myfile.open("myfile.txt", ios::out);
            myfile.close();
            cout << "--- файл --- myfile.txt --- очищен ---" << endl;
        }
        else {
            myfile.open("myfile.txt", ios::app); // 7.3.5
            myfile << myStr << endl;
            myfile.close();
        }
    }

    // 5. Запишите полученную строку в конец текстового файла 
    // (то есть не стирая предыдущего содержимого) и запросите 
    // у пользователя снова строку (достигается это за счёт 
    // бесконечного цикла).

    // 6. Если пользователь вводит read, то в консоль должно 
    // быть выведено всё содержимое текстового файла. При этом 
    // сама строка "read" в файл не должна попасть.

    // 7. Если пользователь вводит erase, то необходимо очистить 
    // файл. При этом сама строка "erase" в файл не должна попасть.

    // 8. Если пользователь вводит exit, то необходимо завершить 
    // программу (например, с помощью break из бесконечного цикла). 
    // При этом сама строка "exit" в файл не должна попасть.

    cout << "Hello World!" << endl;
}
