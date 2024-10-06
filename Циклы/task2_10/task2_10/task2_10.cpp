/* Тест-кейсы:


n = 5;
0 + 0 + 5
0 + 1 + 4
0 + 2 + 3
1 + 1 + 3
1 + 2 + 2


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


    if (n <= 0) // Проверка корректности
    {
        cout << "Введены некорректные данные, n должно быть больше нуля" << endl;
    }
    else
    {
        for (int first_term = 0; first_term < (n / 3) + 1; first_term++) // Делим на 3, т.к. сумма трёх слагаемых
        {
            for (int second_term = first_term; second_term < ((n - first_term) / 2) + 1; second_term++) // Делим на 2, т.к. в половине случаев комбинации повторяются
            {
                cout << first_term << " + " << second_term << " + " << n - first_term - second_term << endl;
            }
        }
    }


    return 0;
}
