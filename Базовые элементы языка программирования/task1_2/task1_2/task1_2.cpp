/* Тест-кейсы:

Стандартный тест-кейс:
x = -1.4;
y = 3.002;
Результат: 24.4663

Тест-кейс для проверки деления на 0:
x = 1.5707963;
y = 0;
Результат: Введены некорректные данные, произошло деление на 0

*/


#include <iostream>
#include <cmath>

using namespace std;

const double epsilon = 0.000001; // Константа, числа меньше которой считаем близкими к нулю


bool isExpressionCorrect(long double x, long double y)
{
    if (pow(cos(x + 2 * y), 2) < epsilon) // Проверка деления на 0 (близкое к 0)
    {
        cout << "Введены некорректные данные, произошло деление на 0" << endl;
        return false;
    }
    // Отрицательность корня проверять не надо, т.к. в числителе сумма экспонент (>0), а в знаменателе квадрат (>=0)
    return true;
}


long double F(long double x, long double y)
{
    return 0.2 * x * y + sqrt((exp(x - 1) + exp(y - 1)) / pow(cos(x + 2 * y), 2));
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
