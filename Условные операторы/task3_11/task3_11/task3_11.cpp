﻿/* Тест-кейсы:

49, 15 -> 16 февраля 2004 года
28, 10 -> 11 мая 2002 года
36, 10 -> 11 января 2003 года
-5, 10 -> Неправильное количество месяцев
15, 28 -> Неправильное количество дней

*/


#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    int m;
    short n;

    // Ввод данных и проверка корректности
    cout << "Введите m: ";
    cin >> m;
    if (m < 0)
    {
        cout << "Неправильное количество месяцев" << endl;
        return 0;
    }
    cout << "Введите n: ";
    cin >> n;
    if ((n < 0) || (n > 20))
    {
        cout << "Неправильное количество дней" << endl;
        return 0;
    }


    // Массив названий месяцев в родительном падеже
    const char* MonthsInGenitiveForm[12] = { "января", "февраля", "марта", "апреля", "мая", "июня",
        "июля", "августа", "сентября", "октября", "ноября", "декабря" };


    cout << 1 + n << " " << MonthsInGenitiveForm[m % 12] << " " << 2000 + m / 12 << " года" << endl;

    return 0;
}
