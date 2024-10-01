/* Тест-кейсы:

Стандартный тест-кейс:
X = 583;
Результат: 123

Тест кейс для проверки отрицательных чисел:
X = -583;
Результат: -123

*/


#include <iostream>
using namespace std;


bool isNumberCorrect(short number)
{
    return (abs(number) >= 100) && (abs(number) <= 999);
}


int main()
{
    setlocale(LC_ALL, "Russian");

    short X, Y, sign, digit1, digit2, digit3;

    // Ввод информации
    cout << "Введите трёхзначное число X: ";
    cin >> X;


    if (isNumberCorrect(X)) // Проверка, что число трёхзначное
    {   
        sign = X / abs(X); // Сохраняем знак для работы также с отрицательными трёхзначными числами
        X = abs(X);

        // Получение цифр
        digit3 = X % 10;
        X /= 10;
        digit2 = X % 10;
        X /= 10;
        digit1 = X % 10;


        Y = sign * (((digit2 + digit3) % 10) * 100 + abs(digit1 - digit3) * 10 + (digit2 % digit1));
        // Вывод информации
        cout << "Число Y: " << Y << endl;
    }
    else
    {
        cout << "Некорректные данные, нужно ввести трёхзначное число" << endl;
    }


    return 0;
}
