
#include <iostream>
#include <cmath> //библиотека для работы с математическими функциями

using namespace std; 


double F(double x) {
    return sin(x); //Возвращает синус указанного угла
}


//метод принимает 2 аргумента  с типом даннхы double 
//вычисление интеграла на отрезке [a, b] методом Ньютона-Котеса открытого типа 4-го порядка
double NewtonCotesOpen4(double a, double b) { 
    const int n = 4; //порядок метода
    double c[3] = { 2.0, -1.0, 2.0 }; //весовые коэффициенты
    const double K = 3.0; //делитель
    double h = (b - a) / n; //величина шага
    double res = 0;
    double x; 
        for (int i = 1; i <= n - 1; i++) { 
            x = a + i * h;
            res += c[i - 1] * F(x); 
        }
    return res * (b - a) / K;
}


//метод принимает 3 аргумента, 2 с типом даннхы double и один с типом даннхы int 
//вычисление интеграла на отрезке [a, b] как суммы интегралов на n подинтервалах
double SumSubIntervals(double a, double b, int n) {
        double res = 0; 
        double h = (b - a) / n; 
        for (int i = 1; i <= n; i++) { 
            res += NewtonCotesOpen4(a + (i - 1) * h, a + i * h); 
        }
        return res;
}



int main()
{
    double a = 0; 
    double b = 3.14; 
    double EPS = 0.00001; //погрешность численного интегрирования
    int n = 1; //количество подинтервалов интегрирования
    double lcur = SumSubIntervals(a, b, n); //значение интеграла на текущем шаге итерации
    double lpre; //значение интеграла на предыдущем шаге итерации
        do { 
            lpre = lcur; n *= 2; 
            lcur = SumSubIntervals(a, b, n); 
            cout << " l = " << lcur << " при n = " << n << " e = " << abs(lcur - lpre) << std::endl;
            } while (abs(lcur - lpre) < EPS);

    std::cout << "-------------------" << std::endl;
    std::cout << " l = " << lcur << " при n = " << n << " e = " << abs(lcur - lpre) << std::endl;

    return 0;
}