#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    // Ввод данных
    long double x, sum = 0, a;
    int n;

    cout << "Введите x: ";
    cin >> x;
    a = x; // Первый элемент
    cout << "Введите n: ";
    cin >> n;


    if (n < 0)
        cout << "n должен быть неотрицательным";
    else
    {
        for (int i = 1; i <= n; ++i) // Считаем значение на основе предыдущих
        {
            sum += a;
            // Следующий элемент получаем умножением предыдущего на отношение соседних элементов
            a *= -x * x / ((2 * i) * (2 * i + 1));
        }
        cout << "sin(" << x << ") = " << sum << endl;
    }

    return 0;
}
