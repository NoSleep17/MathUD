#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <math.h>
#define float double
using namespace std;
float fx(float x)
{
    return 2 * pow(2.71828, pow(x, 5) - pow(x, 3)) - 5 * pow(x, 3) - x + log(x + 45) + 20;
}
float fx_prime(float x)
{
    return 2*(5*pow(x,4)-3*pow(x,2))* pow(2.71828, pow(x, 5) - pow(x, 3))  - 15 * pow(x, 2) - 1 + 1 / (x + 45);
}
float f2x(float x) 
{
    return 3*pow(2.71828,pow(x,5)-pow(x,4))+pow(x,2)-20*x+log(x+25)-10;
}
float f2x_prime(float x)
{
    return 3*(5*pow(x,4)-4*pow(x,3))*pow(2.71828,pow(x,5)-pow(x,4))+2*x-20+1/(x+25);
}
//pass f function to gradient decent
float gradient_decent(float x)
{
    float learningRate = 0.001;
    float epsilon = 0.00001;
    float x_new = x;
    float x_old = x_new - 10 * epsilon;
    while (abs(x_new - x_old) > epsilon)
    {
        x_old = x_new;
        x_new = x_old - learningRate * fx_prime(x_old);
    }
    return x_new;
}
float gradient_decent2(float x)
{
    float learningRate = 0.001;
    float epsilon = 0.00001;
    float x_new = x;
    float x_old = x_new - 10 * epsilon;
    while (abs(x_new- x_old)>epsilon)
    {
        x_old = x_new;
        x_new = x_old - learningRate * f2x_prime(x_old);
    }
    return x_new;
}

int main()
{
    // 2e^(x^5-x^3)-5x^3 -x + ln(x+45) +20
    cout << "f(X) Minimum: " << fx(gradient_decent(1)) << endl;
    cout << "g(x) Minimum: " << f2x(gradient_decent2(1)) << endl;
    return 0;

}