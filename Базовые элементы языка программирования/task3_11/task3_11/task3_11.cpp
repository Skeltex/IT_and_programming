/* Тест-кейсы:

Стандартный тест-кейс:
X = 123;
Результат: 321

Тест кейс для проверки отрицательных чисел:
X = -123;
Результат: -321

Тест кейс для проверки отбрасывания одного ведущего нуля числа Y:
X = 850;
Результат: 58

Тест кейс для проверки отбрасывания двух ведущих нулей числа Y:
X = 800;
Результат: 8

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

    short X, Y, sign, digit1, digit2, digit3, sum_of_digits, product_of_digits;

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

        sum_of_digits = digit1 + digit2 + digit3;
        product_of_digits = digit1 * digit2 * digit3;
        Y = sign * (digit3 * 100 + digit2 * 10 + digit1);

        // Вывод информации
        cout << "Сумма цифр числа: " << sum_of_digits << endl;
        cout << "Произведение цифр числа: " << product_of_digits << endl;
        cout << "Число Y: " << Y << endl;
    }
    else
    {
        cout << "Некорректные данные, нужно ввести трёхзначное число" << endl;
    }


    return 0;
}
