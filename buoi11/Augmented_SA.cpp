#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x1, double x2) 
{
    //them dau am neu la bai toan tim maximum
    return 6 * pow(x1, 2) + 4 * x1 * x2 + 3 * pow(x2, 2);
}

double h(double x1, double x2) 
{
    return x1 + x2 - 5;
}

double L(double x1, double x2, double lambda, double rk) 
{
    return f(x1, x2) + lambda * h(x1, x2) + rk * pow(h(x1, x2), 2);
}

void update_x(double& x1, double& x2, double lambda, double rk) 
{
    x1 = (-90 * pow(rk, 2) + 9 * rk * lambda - 6 * lambda + 60 * rk) / ((14 - 5 * rk) * (12 + 2 * rk));
    x2 = (20 * rk - 2 * lambda) / (14 - 5 * rk);
}

void update_lambda(double& lambda, double x1, double x2, double rk) {
    lambda = lambda + 2 * rk * h(x1, x2);
}

int main() {
    double x1 = 0, x2 = 0; 
    double lambda = 0; 
    double rk = 1; 
    double h_value = h(x1, x2); 

    cout << "Ham so: f(x1,x2) = 6x1^2 + 4x1x2 + 3x2^2";
    cout << "\nRang buoc: h(x1,x2) = x1 + x2 - 5\n\n";

    cout << "lambda\t\tx1\t\tx2\t\th\n";
    while (abs(h_value) >= pow(10, -5))
    //for (int i = 0; i < 100; i++)
    {  
        update_x(x1, x2, lambda, rk);
        update_lambda(lambda, x1, x2, rk);
        h_value = h(x1, x2);

        cout << fixed << setprecision(5) 
            << lambda << "\t" << x1 << "\t" << x2 << "\t\t" << h_value << "\n";
    }

    cout << fixed << setprecision(5) << "\nMinimum: " << f(x1, x2) << " tai x1 = " << x1 << ", x2 = " << x2 << "\n";

    return 0;
}