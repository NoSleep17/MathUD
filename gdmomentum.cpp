#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <math.h>

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
float gradient_decent_with_momemtum(float x)
{
    float learningRate = 0.0001;
    float epsilon = 0.0000001;
    float x_new = x;
    float x_old = x_new - 10 * epsilon;
    float momentum = 0.1;
    while (abs(x_new - x_old) > epsilon)
    {
        x_old = x_new;
        x_new = x_old - learningRate * fx_prime(x_old) + momentum * (x_new - x_old);
    }
    return x_new;

}
float gradient_decent_with_momemtum2(float x)
{
    float learningRate = 0.001;
    float epsilon = 0.00001;
    float x_new = x;
    float x_old = x_new - 10 * epsilon;
    float momentum = 0.1;
    while (abs(x_new - x_old) > epsilon)
    {
        float deltax  = x_new - x_old;
        x_old = x_new;
        x_new = x_old - learningRate * f2x_prime(x_old) + momentum * deltax;
    }
    return x_new;


}

int main()
{
// 2e^(x^5-x^3)-5x^3 -x + ln(x+45) +20
    cout << "f(x) Minimum: " << fx(gradient_decent_with_momemtum(1))<<endl;
    cout << "g(x) Minimum: " << f2x(gradient_decent_with_momemtum2(1))<<endl;
    return 0;

}