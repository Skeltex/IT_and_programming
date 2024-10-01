/* Тест-кейсы:

Стандартный тест-кейс:
x = 2.5;
y = -6.1;
Результат: 0.740367

Тест кейс для проверки деления на 0:
x = 0;
y = 0;
Результат: Введены некорректные данные, произошло деление на 0

Тест кейс для проверки подлогарифмического выражения:
x = 1;
y = 1;
Результат: Введены некорректные данные, подлогарифмическое выражение должно быть положительно

*/


#include <iostream>
#include <cmath>

using namespace std;

const double epsilon = 0.000001; // Константа, числа меньше которой считаем близкими к нулю


bool isExpressionCorrect(long double x, long double y)
{
    if (abs(sin((x + y) * (x + y))) < epsilon) // Проверка деления на 0 (близкое к 0)
    {
        cout << "Введены некорректные данные, произошло деление на 0" << endl;
        return false;
    }
    if (pow(cos(x + y), 2) / sin((x + y) * (x + y)) < epsilon) // Проверка подлогарифмического выражения
    {
        cout << "Введены некорректные данные, подлогарифмическое выражение должно быть положительно" << endl;
        return false;
    }
    // Отрицательность корня проверять не надо, т.к. сумма квадрата (>=0) и экспоненты (>0)
    return true;
}


long double F(long double x, long double y)
{
    return sqrt(pow(log(pow(cos(x + y), 2) / sin((x + y) * (x + y))), 2) + exp(x * x * y));
}


int main()
{
    setlocale(LC_ALL, "Russian");

    long double x, y, result;

    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;


    if (isExpressionCorrect(x, y))
    {
        result = F(x, y);
        cout << "Результат: " << result << endl;
    }


    return 0;
}
