#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues> 
using namespace std;
using namespace Eigen;

double find_det(MatrixXd A, int k)
{
	double s = 1;
	double det = 0;
	MatrixXd B(A.rows(), A.cols());

	if (k == 1)
	{
		return A(0, 0);
	}
	else
	{
		det = 0;
		for (int c = 0; c < k; c++)
		{
			int m = 0;
			int n = 0;
			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < k; j++)
				{
					B(i, j) = 0;
					if (i != 0 && j != c)
					{
						B(m, n) = A(i, j);
						if (n < (k - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			det = det + s * (A(0, c) * find_det(B, k - 1));
			s = -1 * s;
		}
	}
	return det;
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


MatrixXd inverse_Matrix(MatrixXd A)
{
	double ratio, a;
	MatrixXd augment(A.rows(), A.cols() * 2);
	for (int i = 0; i < augment.rows(); i++)
	{
		for (int j = 0; j < augment.cols(); j++)
		{
			if (j < A.rows())
				augment(i, j) = A(i, j);
			else
				augment(i, j) = (i == (j - A.rows())) ? 1 : 0;
		}
	}

	for (int i = 0; i < A.rows(); i++)
	{
		for (int j = 0; j < A.rows(); j++)
		{
			if (i != j)
			{
				ratio = augment(j, i) / augment(i, i);
				for (int k = 0; k < augment.cols(); k++)
				{
					augment(j, k) -= ratio * augment(i, k);
				}
			}
		}
	}

	for (int i = 0; i < A.rows(); i++)
	{
		a = augment(i, i);
		for (int j = 0; j < augment.cols(); j++)
		{
			augment(i, j) /= a;
		}
	}

	MatrixXd kq(A.rows(), A.cols());
	for (int i = 0; i < A.rows(); i++)
	{
		for (int j = 0; j < A.cols(); j++)
		{
			kq(i, j) = augment(i, j + A.cols());
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
	cout << "Enter matrix dimension: "; cin >> row >> col;
	cout << "\nEnter matrix A: ";
	MatrixXd A(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> A(i, j);

	EigenSolver<MatrixXd> solver(A);
	MatrixXd evalues = solver.eigenvalues().real().matrix();

	MatrixXd evectors = fixZero(solver.eigenvectors().real());

	MatrixXd D(A.rows(), A.cols());
	D.setZero();
	MatrixXd D1(A.rows(), A.cols());
	D1.setZero();
	for (int i = 0; i < D.rows(); i++)
		for (int j = 0; j < D.cols(); j++)
			if (i == j) 
			{
				D(i, j) = evalues(i);
				D1(i, j) = evalues(i);
			}
	int S = 1, T = 3, F = 2;

    for (int i = 0; i < T - 1; i++) 
	{
        D(i, i) *= D1(i, i);
    }
	MatrixXd ans = fixZero(multiply(multiply(evectors, D, evectors.rows(), evectors.cols(), D.cols()),
		inverse_Matrix(evectors), evectors.rows(), evectors.cols(), evectors.cols()));
    cout << "Max probability in state " << F << ", after " << T << " time, start from state  " << S << " is: " << ans(S, F) << endl;
    return 0;
}