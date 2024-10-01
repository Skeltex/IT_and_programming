/* Тест-кейсы:

236, 5, 2 -> 125
537, 5, 3 -> 22
954, 7, 6 -> 65
554, 7, 6 -> 8
25, 3, 5 -> Введены некорректные данные, число a должно быть трёхзначным
425, 13, 5 -> Введены некорректные данные, число x должно быть трёхзначным
225, 3, 15 -> Введены некорректные данные, число y должно быть трёхзначным

*/


#include <iostream>
#include <cmath>
using namespace std;


bool IsNumberCorrect(short number, short need_lenght)
{
    return (abs(number) >= pow(10, need_lenght - 1)) && (abs(number) <= (pow(10, need_lenght) - 1));
}


int main()
{
    setlocale(LC_ALL, "Russian");

    short a, x, y, sign, digit1, digit2, digit3, sum_of_digits_a;

    // Ввод данных и проверка корректности
    cout << "Введите a: ";
    cin >> a;
    if (!IsNumberCorrect(a, 3))
    {
        cout << "Введены некорректные данные, число a должно быть трёхзначным" << endl;
        return 0;
    }
    cout << "Введите x: ";
    cin >> x;
    if (!IsNumberCorrect(x, 1))
    {
        cout << "Введены некорректные данные, число x должно быть однозначным" << endl;
        return 0;
    }
    cout << "Введите y: ";
    cin >> y;
    if (!IsNumberCorrect(y, 1))
    {
        cout << "Введены некорректные данные, число y должно быть однозначным" << endl;
        return 0;
    }




    // Сохраняем знак для работы также с отрицательными числами
    sign = a / abs(a);
    a = abs(a);

    // Получение цифр
    digit3 = a % 10;
    a /= 10;
    digit2 = a % 10;
    a /= 10;
    digit1 = a % 10;


    sum_of_digits_a = digit1 + digit2 + digit3;

    if ((sum_of_digits_a % x == 0) && (sum_of_digits_a % y == 0))
    {
        digit1 = abs(digit1 - 5);
        digit2 = abs(digit2 - 5);
        digit3 = abs(digit3 - 5);
    }
    else if ((sum_of_digits_a % x == 0) && (sum_of_digits_a % y != 0))
    {
        digit1 = digit1 * 2 % 10;
        digit2 = digit2 * 2 % 10;
        digit3 = digit3 * 2 % 10;
    }
    else if ((sum_of_digits_a % x != 0) && (sum_of_digits_a % y == 0))
    {
        digit1 = (digit1 + 1) % 10;
        digit2 = (digit2 + 1) % 10;
        digit3 = (digit3 + 1) % 10;
    }
    else // Сумма цифр не кратна x и y
    {
        digit1 = abs(digit1 - 1);
        digit2 = abs(digit2 - 1);
        digit3 = abs(digit3 - 1);
    }

    a = sign * (digit1 * 100 + digit2 * 10 + digit3);
    cout << "Новое число a: " << a << endl;

    return 0;
}
