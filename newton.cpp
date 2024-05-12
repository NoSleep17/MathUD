#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <math.h>
#define float double
using namespace std;

float f2x(float x)
{
    return 3 * pow(2.71828, pow(x, 5) - pow(x, 4)) + pow(x, 2) - 20 * x + log(x + 25) - 10;
}
float f2x_prime(float x)
{
    return 3 * (5 * pow(x, 4) - 4 * pow(x, 3)) * pow(2.71828, pow(x, 5) - pow(x, 4)) + 2 * x - 20 + 1 / (x + 25);
}
float f2x_prime_prime(float x)
{
    return 3 * pow(2.71828, pow(x, 5) - pow(x, 4)) * (20 * pow(x, 3) - 12 * pow(x, 2) + (5 * pow(x, 4) - 4 * pow(x, 3)) * (5 * pow(x, 4) - 4 * pow(x, 3))) - 1 / ((x + 25) * (x + 25)) + 2;

}
float newtonRaps(float x)
{
    float learningRate = 0.001;
    float epsilon = 0.00001;
    float x_new = x;
    float x_old = x_new - 10 * epsilon;
    while (abs(x_new - x_old) > epsilon)
    {
        x_old = x_new;
        x_new = x_old - f2x_prime(x_old) / f2x_prime_prime(x_old);
        cout << x_new << endl;
    }
    return x_new;
}


int main()
{
    cout << "Minimum: " << f2x(newtonRaps(0)) << endl;
    cout << f2x(1.2) << endl;
    cout << f2x_prime(1.2) << endl;
    cout << f2x_prime_prime(1.2);
    return 0;

}