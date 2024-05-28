#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;



// Cập nhật biến quyết định x1 và x2
void update_x(double& x1, double& x2, double lambda, double rk) 
{
    x1 = (-90 * pow(rk, 2) + 9 * rk * lambda - 6 * lambda + 60 * rk) / ((14 - 5 * rk) * (12 + 2 * rk));
    x2 = (20 * rk - 2 * lambda) / (14 - 5 * rk);
}
// Cập nhật đa thức nhân tử Lagrange lambda
void update_lambda(double& lambda, double x1, double x2, double rk) 
{
    lambda = lambda + 2 * rk * h(x1, x2);
}
// Định nghĩa hàm ràng buộc
double h(double x1, double x2) 
{
    return x1 + x2 - 5;
}

// Định nghĩa hàm mục tiêu
double f(double x1, double x2) 
{
    // Thêm dấu trừ nếu bạn đang giải bài toán tìm giá trị lớn nhất
    return 6 * pow(x1, 2) + 4 * x1 * x2 + 3 * pow(x2, 2);
}
// Tính hàm Lagrange
double L(double x1, double x2, double lambda, double rk) 
{
    return f(x1, x2) + lambda * h(x1, x2) + rk * pow(h(x1, x2), 2);
}

// Cập nhật biến quyết định x1 và x2
void update_x(double& x1, double& x2, double lambda, double rk) 
{
    x1 = (-90 * pow(rk, 2) + 9 * rk * lambda - 6 * lambda + 60 * rk) / ((14 - 5 * rk) * (12 + 2 * rk));
    x2 = (20 * rk - 2 * lambda) / (14 - 5 * rk);
}

int main() 
{
    double x1 = 0, x2 = 0; 
    double lambda = 0; 
    double rk = 1; 
    double h_value = h(x1, x2); 

    cout << "f(x1, x2) = 6x1^2 + 4x1x2 + 3x2^2";
    cout << "\nRàng buộc: h(x1, x2) = x1 + x2 - 5\n\n";

    cout << "lambda\t\tx1\t\tx2\t\th\n";
    while (abs(h_value) >= pow(10, -5))
    {  
        update_x(x1, x2, lambda, rk);
        update_lambda(lambda, x1, x2, rk);
        h_value = h(x1, x2);

        cout << fixed << setprecision(5) 
            << lambda << "\t" << x1 << "\t" << x2 << "\t\t" << h_value << "\n";
    }

    cout << fixed << setprecision(5) << "\nGiá trị tối thiểu: " << f(x1, x2) << " tại x1 = " << x1 << ", x2 = " << x2 << "\n";

    return 0;
}