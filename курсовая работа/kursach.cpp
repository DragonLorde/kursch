
#include <iostream>
#include <cmath> //���������� ��� ������ � ��������������� ���������

using namespace std; 


double F(double x) {
    return sin(x); //���������� ����� ���������� ����
}


//����� ��������� 2 ���������  � ����� ������ double 
//���������� ��������� �� ������� [a, b] ������� �������-������ ��������� ���� 4-�� �������
double NewtonCotesOpen4(double a, double b) { 
    const int n = 4; //������� ������
    double c[3] = { 2.0, -1.0, 2.0 }; //������� ������������
    const double K = 3.0; //��������
    double h = (b - a) / n; //�������� ����
    double res = 0;
    double x; 
        for (int i = 1; i <= n - 1; i++) { 
            x = a + i * h;
            res += c[i - 1] * F(x); 
        }
    return res * (b - a) / K;
}


//����� ��������� 3 ���������, 2 � ����� ������ double � ���� � ����� ������ int 
//���������� ��������� �� ������� [a, b] ��� ����� ���������� �� n �������������
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
    double EPS = 0.00001; //����������� ���������� ��������������
    int n = 1; //���������� ������������� ��������������
    double lcur = SumSubIntervals(a, b, n); //�������� ��������� �� ������� ���� ��������
    double lpre; //�������� ��������� �� ���������� ���� ��������
        do { 
            lpre = lcur; n *= 2; 
            lcur = SumSubIntervals(a, b, n); 
            cout << " l = " << lcur << " ��� n = " << n << " e = " << abs(lcur - lpre) << std::endl;
            } while (abs(lcur - lpre) < EPS);

    std::cout << "-------------------" << std::endl;
    std::cout << " l = " << lcur << " ��� n = " << n << " e = " << abs(lcur - lpre) << std::endl;

    return 0;
}