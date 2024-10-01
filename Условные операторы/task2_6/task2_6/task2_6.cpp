/* Тест-кейсы:

-8 -> Корень из отрицательного числа
-4 -> Деление на ноль
4 -> Деление на ноль
2 -> Деление на ноль
0 -> Логарифм из неположительного числа
1 -> Логарифм из неположительного числа
-1 -> Логарифм из неположительного числа
3 -> 2.70365

*/


#include <iostream>
#include <cmath>

using namespace std;

const double epsilon = 0.000001; // Константа, числа меньше которой считаем близкими к нулю


bool isExpressionCorrect(long double x)
{
    if ((x * x - 1) <= epsilon) // Проверка подлогарифмического выражения на неположительность
    {
        cout << "Логарифм из неположительного числа" << endl;
        return false;
    }

    if ((x + 5) < epsilon) // Проверка подкоренного выражения на отрицательность
    {
        cout << "Корень из отрицательного числа" << endl;
        return false;
    }

    if ((abs(x * x - 16) < epsilon) || (abs(x - 2) < epsilon)) // Проверка деления на 0
    {
        cout << "Деление на ноль" << endl;
        return false;
    }

    return true;
}


long double F(long double x)
{
    return sin(log(x * x - 1)) / (x * x - 16) + sqrt(x + 5) / abs(x - 2);
}


int main()
{
    setlocale(LC_ALL, "Russian");

    long double x, result;

    cout << "Введите x: ";
    cin >> x;


    if (isExpressionCorrect(x))
    {
        result = F(x);
        cout << "Результат: " << result << endl;
    }


    return 0;
}
