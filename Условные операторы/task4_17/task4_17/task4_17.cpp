#include <iostream>
#include <cmath>

using namespace std;

const double epsilon = 0.0001; // Константа, числа меньше которой считаем близкими к нулю


long double min(long double a, long double b, long double c)
{
    if (a < b)
    {
        if (a < c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (b < c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}


long double max(long double a, long double b, long double c)
{
    if (a > b)
    {
        if (a > c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (b > c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");

    long double a, b, c, min_side, average_side, max_side, lateral_side, base_side, p, h, S, R, r;
    bool equilateral = false, isosceles = false, scalene = false, rectangular = false;

    // Ввод данных и проверка корректности
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите c: ";
    cin >> c;
    
    if ((a < epsilon) || (b < epsilon) || (c < epsilon))
    {
        cout << "Введены некорректные данные, все стороны треугольника должны быть положительными" << endl;
        return 0;
    }


    min_side = min(a, b, c);
    max_side = max(a, b, c);
    average_side = a + b + c - min_side - max_side;
    p = 0.5 * (a + b + c);


    // Определение типа треугольника
    cout << "Тип: ";
    if (abs((min_side + average_side) - max_side) < epsilon)
    {
        cout << "вырожденный";
        return 0;
    }
    else if (((min_side + average_side) - max_side) < epsilon)
    {
        cout << "не существует";
        return 0;
    }
    else if (abs(min_side - max_side) < epsilon)
    {
        cout << "равносторонний";
        equilateral = true;
    }
    else if ((abs(average_side - min_side) < epsilon) || (abs(average_side - max_side) < epsilon))
    {
        cout << "равнобедренный";
        isosceles = true;
    }

    
    // В отдельном if, а не в предыдущей цепочке if else, потому что может быть прямоугольным одновременно с предыдущими условиями
    if (abs(pow(min_side, 2) + pow(average_side, 2) - pow(max_side, 2)) < epsilon)
    {
        if (equilateral || isosceles) // Если уже выявились признаки до этого, то добавляем "и"
        {
            cout << " и ";
        }
        cout << "прямоугольный";
        rectangular = true;
    }


    if (!(equilateral || isosceles || rectangular))
    {
        cout << "разносторонний";
        scalene = true;
    }
    cout << endl;



    // Описание сторон прямоугольного и равнобедренного треугольников и вычисления остальных
    if (rectangular)
    {
        cout << min_side << " и " << average_side << " - катеты, " << max_side << " - гипотенуза." << endl;
        h = min_side * average_side / max_side;
        cout << "Высота, проведённая из вершины прямого угла: " << h << endl;
        if (!isosceles)
        {
            cout << "Медиана, проведённая из вершины прямого угла: " << 0.5 * max_side << endl;
        }
        S = 0.5 * min_side * average_side;
        R = 0.5 * max_side;
        r = 0.5 * (min_side + average_side - max_side);
    }
    else if (isosceles)
    {
        //else, т.к. взаимоисключающие - если прямоугольный, то уже не надо рассказывать про стороны равнобедренного
        if (average_side == min_side)
        {
            lateral_side = min_side;
            base_side = max_side;
        }
        else
        {
            lateral_side = max_side;
            base_side = min_side;
        }
        cout << lateral_side << " и " << lateral_side << " - боковые стороны, " << base_side << " - основание." << endl;
        h = 0.5 * sqrt(4 * pow(lateral_side, 2) - pow(base_side, 2));
        cout << "Высота, проведённая к основанию: " << h << endl;
        S = 0.5 * base_side * h;
        R = (a * b * c) / (4 * S);
        r = S / p;
    }
    else if (equilateral)
    {
        // Можно было рассматривать р/с как частный случай р/б, но отделил, чтобы считать по более простым формулам для р/с
        h = a * sqrt(3.0) * 0.5;
        cout << "Высота: " << h << endl;
        S = 0.5 * a * h;
        R = a / sqrt(3.0);
        r = a * sqrt(3.0) / 6;
    }
    else // Разносторонний
    {
        S = sqrt(p * (p - a) * (p - b) * (p - c));
        R = a * b * c / (4 * S);
        r = S / p;
    }


    cout << "S = " << S << endl;
    cout << "R = " << R << endl;
    cout << "r = " << r << endl;

    return 0;
}
