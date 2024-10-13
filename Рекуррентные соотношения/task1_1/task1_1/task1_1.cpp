#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    // Ввод данных
    long double y1, y2, y;
    int n;

    cout << "Введите y1: ";
    cin >> y1;
    cout << "Введите y2: ";
    cin >> y2;
    cout << "Введите n: ";
    cin >> n;


    if (n < 1)
        cout << "n должен быть натуральным";
    else if (n == 1)
        cout << "y1 = " << y1;
    else if (n == 2)
        cout << "y2 = " << y2;
    else
    {
        for (int i = 0; i < n - 2; ++i) // Первые 2 члена уже есть - нужно прокрутить ещё n - 2 раза
        {
            y = y2 / 2.0 + y1 / 3.0;
            y1 = y2;
            y2 = y;
        }
        cout << "y" << n << " = " << y2;
    }
    cout << endl;

    return 0;
}
