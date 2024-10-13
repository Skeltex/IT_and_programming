// Ряд при abs(x) < 1 сходится к 1 / (x + 1)
// Ряд при abs(x) >= 1 расходится


#include <iostream>
#include <cmath>

using namespace std;


const long double epsilon = 0.000001;


int main()
{
    setlocale(LC_ALL, "Russian");

    // Ввод данных
    long double x, a = 1, a_next, sum = 0;
    int n;

    cout << "Введите x: ";
    cin >> x;
    cout << "Введите n: ";
    cin >> n;


    if (n < 0)
        cout << "n должен быть неотрицательным";
    else
    {
        for (int i = 0; i <= n; ++i) // Считаем значение на основе предыдущих
        {
            sum += a;
            a_next = a * -x;
            if (abs(a_next - a) < epsilon)
            {
                cout << "Последовательность сходится к " << sum << endl;
                cout << "Для проверки хватило " << i + 1 << " шагов" << endl;
                // i + 1, т.к. на итерации i мы уже вычисляем a[i + 1] как a_next
                return 0;
            }
            a = a_next;  
        }
        cout << "Последовательность расходится при проверке первых " << n << " шагов"; // Если не сошлась за n шагов
    }

    return 0;
}
