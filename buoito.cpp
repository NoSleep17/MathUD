#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <math.h>
#include <numeric>
#include <iterator>
#include "Eigen/Eigenvalues"
#include "Eigen/Dense"
using namespace std;
using namespace Eigen;

void reverse_matrix(MatrixXd &matrix)
{
    for (int j = 0; j < matrix.cols() / 2; ++j)
        for (int i = 0; i < matrix.rows(); ++i)
        {
            swap(matrix(i, j), matrix(i, matrix.cols() - 1 - j));
        }
}

void TransposeInPlace(MatrixXd &V, MatrixXd &V1, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            V1(i, j) = V(j, i);
        }
    }
}
double dotProduct(VectorXd v1, VectorXd v2, int n)
{
    double ans = 0;
    if (v1.size() != v2.size())
        return 1;
    else
    {
        for (int i = 0; i < n; ++i)
            ans = ans + (v1[i] * v2[i]);
        return ans;
    }
}
int main()
{
    int m, n;
    cin >> m >> n;

    MatrixXd A(m, n), AT(n, m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            A(i, j) = x;
        }
    }
    TransposeInPlace(A, AT, m, n);

    MatrixXd U(m, m), D(m, n), V(n, n), VT(n, n), ATA;
    U.setZero();
    VT.setZero();
    D.setZero();
    ATA = AT * A;
    cout << ATA << '\n';
    SelfAdjointEigenSolver<MatrixXd> eigensolver(ATA);
    V = eigensolver.eigenvectors();
    // cout << V << '\n';
    reverse_matrix(V);

    MatrixXd hold1 = eigensolver.eigenvalues().matrix();
    vector<long double> a;

    for (int i = 0; i < hold1.size(); i++)
    {
        if (hold1(i, 0) > 10e-10)
        {
            a.push_back((hold1(i, 0)));
        }
    }
    sort(a.rbegin(), a.rend());
    int pos = a.size();
    for (int i = 0; i < a.size(); i++)
    {
        D(i, i) = sqrt(a[i]);
    }

    for (int i = 0; i < a.size(); i++)
    {
        MatrixXd Ui = (1.0 / D(i, i)) * A * V.col(i);
        for (int j = 0; j < m; j++)
        {
            U(j, i) = Ui(j, 0);
        }
    }

    while (pos < m)
    {
        MatrixXd e3(m, 1);
        for (int i = 0; i < m; i++)
        {
            e3(i, 0) = 0;
        }
        e3(pos, 0) = 1;
        MatrixXd Ui = e3;
        for (int i = 0; i < pos; i++)
        {
            MatrixXd ui = U.col(i);

            ui = (dotProduct(e3, ui, m) / dotProduct(ui, ui, m)) * ui;
            Ui = Ui - ui;
        }
        cout << Ui << '\n';
        long double chuanhoa = 0;
        for (int i = 0; i < Ui.rows(); i++)
        {
            chuanhoa += Ui(i, 0) * Ui(i, 0);
        }
        for (int j = 0; j < m; j++)
        {
            U(j, pos) = Ui(j, 0) / sqrt(chuanhoa);
        }
        pos++;
    }
    cout << "Matrix U: " << '\n'
         << U << '\n';
    cout << "Matrix D: " << '\n'
         << D << '\n';
    cout << "Matrix V: " << '\n'
         << V << '\n';

    TransposeInPlace(V, VT, n, n);

    cout << "Matrix VT: " << '\n'
         << VT << '\n';
    MatrixXd AA = U * D * VT;
    cout << "Matrix A = U * D * VT : " << '\n'
         << AA << '\n';
    AA = AA - A;
    cout << "Test secure A - (U * D * VT): " << '\n'
         << AA << '\n';
}
