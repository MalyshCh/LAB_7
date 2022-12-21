#include <iostream>
#include <string>
#include <Windows.h>
#include <regex>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "7 Лабораторная работа. Вопрос 2." << endl;

    // 1. Попросите пользователя ввести своё имя и запишите его 
    // в переменную.

    string userName;
    cout << "Введите ваше имя : ";
    cin >> userName;

    // 2. Сделайте регулярное выражение для проверки корректности 
    // имени (имя должно быть от 2 символов до 32 и содержать 
    // только буквы, причём первая обязательно должна быть заглавной).

    regex regName("^([A-ZА-ЯЁ])[a-zа-яё]{1,31}$");
    if (regex_match(userName, regName)) cout << "Корректный ввод.";
    else cout << "Ошибка: не корректный ввод.";
    cout << endl;

    // 3. Создайте строковую переменную, куда запишите произвольный 
    // текст, но в котором должно быть несколько e-mail адресов.

    string emailList = "Таким образом, рамки и место обучения mail@ONE.com кадров обеспечивает широкому крhidden.post@twho.nuугу специалистов участие в формировании kevin.wer123@12no.netэкономической целесообразности принимаемых решений. С другой стороны на почта@почта.рф чало повседневной работы по формированию позиции трrtyWedRR5TY-fgh.w3e4r@com.ogr ебует от нас анализа экономической целесообразности принимаеnomore@info.spaceмых решений. С другой стороны курс на социально-ориентированный национальный проект позволяет оценить значение направлений прогрессивного развития!thisisfinish@fin.ge";

    // 4. С помощью регулярного выражения вытащите из неё все e-mail 
    // адреса и выведите их в консоль.

    regex regEmail("[a-z0-9_][a-z0-9_\.-]*[a-z0-9_]@([a-z0-9]+[a-z0-9_-]*[a-z0-9]\.)+[a-z0-9]{2,5}", regex_constants::icase);
    smatch match;

    cout << "Строка до обработки :" << endl << emailList << endl;
    while (regex_search(emailList, match, regEmail)) {
        cout << "Найден адрес - " << match.str(0) << endl;
        emailList.erase(emailList.find(match.str(0)), match.str(0).length());
    }
    cout << "Строка после обратки (вытащили из неё все e-mail):" << endl << emailList << endl;

    cout << "Hello World!" << endl;
}
