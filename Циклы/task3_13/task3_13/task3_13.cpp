/* Тест-кейсы:

a = 1;
b = 5;
h = 1;

F(1) = Логарифм из неположительного числа
F(2) = Деление на ноль
F(3) = 2.07944
F(4) = 1.35403
F(5) = 1.05935

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

    if (abs(x - 2) < epsilon) // Проверка деления на 0
    {
        cout << "Деление на ноль" << endl;
        return false;
    }

    return true;
}


long double F(long double x)
{
    return log(x * x - 1) / abs(x - 2);
}


int main()
{
    setlocale(LC_ALL, "Russian");

    long double a, b, h;

    // Ввод данных
    cout << "Введите a: ";
    cin >> a;

    cout << "Введите b: ";
    cin >> b;

    cout << "Введите h: ";
    cin >> h;


    for (long double x = a; x <= b; x += h)
    {
        cout << "F(" << x << ") = ";
        if (isExpressionCorrect(x))
        {
            cout << F(x) << endl;
        }
    }


    return 0;
}
