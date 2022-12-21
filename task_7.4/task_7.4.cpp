#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Settings { // 7.4.9

private:
    //map<string, string> myMap; // 7.4.14
    static map<string, string> myMap; // 7.4.14

public:
    
    Settings(string key, string value)
    {
        myMap[key] = value;
    }

    ~Settings() {}

    //void add(string key, string value) { // 7.4.10
    static void add(string key, string value) { // 7.4.14
        myMap.insert(pair<string, string>(key, value));
    }

    //string get(string key) { // 7.4.11
    static string get(string key) { // 7.4.14
        //return myMap[key];
        map<string, string>::iterator i;
        i = myMap.find(key);
        return i->second;
    }

    //void print() { // 7.4.12
    static void print() { // 7.4.14
        cout << "--- map --- начало ---" << endl;
        for (auto i = myMap.begin(); i != myMap.end(); i++)
            cout << i->first << " >> " << i->second << endl;
        cout << "--- map --- конец ---" << endl;
    }
};

map<string, string> Settings::myMap;

void vectorToConsol(vector<float> vfloat) { // 7.4.3
    cout << "--- vector --- начало ---" << endl;
    for (float n : vfloat) cout << n << " ";
    cout << endl << "--- vector --- конец ---" << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "7 Лабораторная работа. Вопрос 4." << endl;

    // 1. Создайте пустой вектор с типом float.

    vector<float> vctr;

    // 2. Добавьте 5 элементов в вектор.

    vctr = {1.9f, 2.8f, 3.7, 44.06f, 500.55};

    // 3. Создайте функцию, которая принимает вектор и 
    // выводит его в консоли.

    // 4. Вызовите созданную функцию.

    vectorToConsol(vctr);

    // 5. Вставьте ещё один элемент между 3 и 4 элементами 
    // (индексы у них 2 и 3 соответственно).

    vctr.insert(vctr.begin() + 3, 0.304);

    // 6. Проверьте правильность сделанного, выведя вектор 
    // в консоль.

    vectorToConsol(vctr);

    // 7. Удалите последний элемент.

    vctr.erase(vctr.end() - 1);

    // 8. Проверьте правильность сделанного, выведя вектор 
    // в консоль.

    vectorToConsol(vctr);

    // 9. Создайте класс Settings (настройки) и добавьте в 
    // него поле типа Map.

    // 10. Добавьте в класс функцию Add, принимающую 2 
    // строки (ключ и значение) и добавляющая их как новую 
    // пару в Map.

    // 11. Добавьте в класс функцию Get, принимающую строку 
    // (ключ) и возвращающая соответствующее ей значение 
    // в Map.

    // 12. Добавьте в класс функцию Print, которая будет 
    // выводить в консоль содержимое Map.

    // 13. Создайте экземпляр класса Settings и проверьте 
    // работу всех созданных методов.
        
    /* // 7.4.15
    Settings mySet("menu", "меню");
    mySet.add("one", "первый");
    mySet.add("two", "второй");
    mySet.add("three", "третий");
    mySet.print();
    cout << "Значение, соотвествующее 'three' - " << mySet.get("three") << endl;
    */

    // 14. Сделайте поле Map у класса Settings статическим, 
    // а также сделайте статическими все его функции.

    // 15. Закомментируйте предыдущую проверку класса и 
    // проверьте его работу теперь, когда свойства и методы 
    // стали статическими.

    Settings staticMySet("menu", "меню");
    staticMySet.add("one", "первый");
    staticMySet.add("two", "второй");
    staticMySet.add("three", "третий");
    staticMySet.print();
    cout << "Значение, соотвествующее 'three' - " << staticMySet.get("three") << endl;

    cout << "Hello World!" << endl;
}
