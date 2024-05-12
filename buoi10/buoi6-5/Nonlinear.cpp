#include <math.h>
#include <iostream>
#include <vector>
#define rk 1
#define loop 1000
#define gap 1e-3

using namespace std;

double f(double x1, double x2)
{
    return 6 * pow(x1,2) + 4*x1*x2 + 3* pow(x2,2); 
}

double solve_h(double x1, double x2)
{
    return x1 + x2 -5;
}

double A ( double x1, double x2, double lamda)
{
    double H = solve_h(x1,x2);
    return f(x1,x2) + lamda * H + (rk * pow(H,2) );
}
double solve_x1 (double lamda )
{

    return (-90*pow(rk,2)+9*rk*lamda-6*lamda+60*rk) / ((14-5*rk)*(12+2*rk));
}
double solve_x2 (double lamda )
{

    return (20*rk -2*lamda) / (14-5*rk);

}
int main()
{
    vector <double> H,X1,X2,Lamda,R;
    double lamda = 0.000,x1,x2,h,r = rk;
    
    for ( int i = 0; i < loop; i++)
    {
        Lamda.push_back(lamda);
        x1 = solve_x1(lamda);
        x2 = solve_x2(lamda);
        h = solve_h(x1,x2);
        lamda += 2*h;
        X1.push_back(x1);
        X2.push_back(x2);
        R.push_back(rk);
        H.push_back(h);
        if (fabs(h) < gap) break;
    }
    Lamda[0] = 0;
    for ( int i = 0; i < Lamda.size(); i++)
    {
        cout <<Lamda[i] <<" "<< R[i]<<" " << X1[i]<<" " <<X2[i]<<" " << H[i] << endl;
    }
    return 0;
}