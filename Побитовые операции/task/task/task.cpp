﻿/* Тест-кейсы:

Стандартный тест-кейс:
n = 4;
i = 2;
Результат:
1. 2^2 = 4
2. 6
3. 4
4. 6
5. n - чётное

*/


#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    short i;

    // Ввод информации
    cout << "Введите n: ";
    cin >> n;

    cout << "Введите i: ";
    cin >> i;


    cout << "1. 2^" << i << " = " << (1 << i) << endl;

    // Биты считаются справа налево, начиная с 1
    cout << "2. " << (n | (1 << (i - 1))) << endl;
    cout << "3. " << (n & ~(1 << (i - 1))) << endl;
    cout << "4. " << (n ^ (1 << (i - 1))) << endl;

    // Проверка чётности работает также для отрицательных чисел
    cout << "5. n - " << (((n | 1) == n) ? "не" : "") << "чётное" << endl;

}
