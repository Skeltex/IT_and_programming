/* Тест-кейсы:


16 -> Простые числа до n: 2 3 5 7 11 13
17 -> Простые числа до n: 2 3 5 7 11 13 17
18 -> Простые числа до n: 2 3 5 7 11 13 17
2 -> Простые числа до n: 2

-3 -> Простых чисел до n нет
1.999 -> Простых чисел до n нет


*/


#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    // Ввод данных
    int n;
    cout << "Введите n: ";
    cin >> n;


    if (n < 2)
    {
        // Введено слишком маленькое n
        cout << "Простых чисел до n нет" << endl;
    }
    else
    {
        // Решето Эратосфена
        int arr_lenght = n + 1;
        bool* arr = new bool[arr_lenght] {false};

        // Инициализируем массив единицами
        for (int i = 2; i < arr_lenght; i++)
        {
            arr[i] = true;
        }

        // Вычёркиваем неподходящие числа
        for (int i = 2; i <= (int)sqrt(n); i++)
        {
            for (int j = i * i; j < arr_lenght; j+=i)
            {
                arr[j] = false;
            }
        }

        // Вывод простых чисел
        cout << "Простые числа до n: ";
        for (int i = 2; i < arr_lenght; i++)
        {
            if (arr[i])
            {
                cout << i << " ";
            }
        }
    }


    return 0;
}
