/* Тест-кейсы:


n = 8;
1
2
2 1
4 2
3 2 1
6 4 2
4 3 2 1
8 6 4 2


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


    if (n < 0) // Проверка корректности
    {
        cout << "Введены некорректные данные, n должно быть больше нуля" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i / 2 + 1; j > 0; j--) // Длина строки
            {
                cout << j * (1 + i % 2) << " "; // Умножаем на 2, если нечётная строка
            }
            cout << endl;
        }
    }


    return 0;
}
