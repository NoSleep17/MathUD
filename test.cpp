#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include "Eigen/Dense"
#include "Eigen/Eigenvalues"
using namespace std;
using namespace Eigen;
MatrixXd tranpose(MatrixXd A, int m, int n)
{
    MatrixXd At(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            At(i, j) = A(j, i);
    return At;
}

double dotProduct(VectorXd v1, VectorXd v2, int n) 
{
    double ans = 0; 
    if (v1.size() != v2.size()) return 1; 
    else {
        for (int i = 0; i < n; ++i)
            ans = ans + (v1[i] * v2[i]); 
        return ans;
    }
}

double mag_square(VectorXd v)
{
    double ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans += v[i] * v[i];
    return ans;
}


MatrixXd multiply(MatrixXd A, MatrixXd B, int m, int n, int y)
{
    MatrixXd kq(m, y);
    kq.setZero();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < n; k++)
            {
                kq(i, j) += A(i, k) * B(k, j);
            }
        }
    }
    return kq;
}

MatrixXd fixZero(MatrixXd A)
{
    for (int i = 0; i < A.rows(); i++)
    {
        for (int j = 0; j < A.cols(); j++)
        {
            if (fabs(A(i, j)) < 1e-10)
            {
                A(i, j) = 0;
            }
        }
    }
    return A;
}

int main()
{
    
    int row, col;
    cout << "==============================================" << endl;
    cout << "Nhap so hang va so cot cho ma tran A: "; cin >> row >> col; 
    cout << "\nNhap phan tu cho ma tran A: "; 
    MatrixXd A(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> A(i, j);
    cout << "\n\nMa tran A ban dau: \n";
    cout << A << "\n\n";
    MatrixXd At = tranpose(A, A.rows(), A.cols()); 
    cout << "Ma tran At: \n";
    cout << At << "\n\n";
    MatrixXd S = multiply(At, A, At.rows(), At.cols(), A.cols());  
    cout << "Ma tran S: \n";
    cout << S << "\n\n";

    MatrixXd U(row, row), Sigma(row, col), V(col, col);

    EigenSolver<MatrixXd> solver(S);  
    MatrixXd evalues = solver.eigenvalues().real().matrix(); 
    cout << "Cac eigenvalue cua ma tran S la:\n" << fixZero(evalues) << "\n\n"; 
    cout << "Ma tran V:\n";
    V = fixZero(solver.eigenvectors().real()); 
    cout << setprecision(5) << V << "\n\n";

    int count = S.rows();
    for (int i = 0; i < evalues.rows(); i++)
        if (fabs(evalues(i, 0)) < 1e-10) count--; 
    //cout << "\ncount = " << count << endl; 
    MatrixXd sig(count, 1);  
    for (int i = 0; i < count; i++)
        sig(i, 0) = sqrt(evalues(i, 0)); 
    //cout << "Cac gia tri sigma la:\n";
   // cout << fixZero(sig) << "\n\n"; 
    Sigma.setZero();
    for (int i = 0; i < Sigma.rows(); i++)
        for (int j = 0; j < Sigma.cols(); j++)
            if (i == j && i < count) Sigma(i, j) = sig(i, 0); 
    cout << "Ma tran Sigma:\n";
    cout << setprecision(5) << Sigma << "\n\n";

    for (int i = 0; i < count; i++)
    {
        MatrixXd left(row, col);
        left = (1 / sig(i, 0)) * A;
        MatrixXd kq(row, 1); 
        kq = multiply(left, V.col(i), left.rows(), left.cols(), 1); 
        U.col(i) = kq; 
    }
    if (count < U.cols())
    {
        int generate = 0;
        for (int i = count; i < U.cols(); i++)
        {
            int countZero = 0;
            for (int j = 0; j < U.rows(); j++)
            {
                if (U(j, i - 1) != 0)
                {
                    U(j, i) = 0;
                    countZero++;
                }
                else U(j, i) = 1;
                //if (countZero == U.rows()) U(U.rows() - 1, i) = 1;
            }
            if (countZero == U.rows()) U(U.rows() - ++generate, i) = 1; 
            for (int j = 0; j < i; j++)
            {
                U.col(i) = U.col(i) - ((dotProduct(U.col(j), U.col(i), U.rows())) / mag_square(U.col(j))) * U.col(j);   
            }  
        }
    }
    
    cout << "Ma tran U:\n";
    cout << U << "\n\n";
    cout << "Thu lai A = U * Sigma * V^t =";
    cout << "\n" << setprecision(5) << fixZero(U * Sigma * tranpose(V, V.rows(), V.cols()));
 

    return 0;
}