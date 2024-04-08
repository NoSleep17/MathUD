#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define SIZE 3

bool check_sym(double A[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (A[i][j] != A[j][i])
				return false;
		}
	}
	return true;
}

double find_det(double a[SIZE][SIZE], int k)
{
	double s = 1;
	double det = 0;
	double b[SIZE][SIZE];

	if (k == 1)
		return a[0][0];

	for (int c = 0; c < k; c++)
	{
		int m = 0;
		int n = 0;
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
			{
				b[i][j] = 0;
				if (i != 0 && j != c)
				{
					b[m][n] = a[i][j];
					if (n < (k - 2))
						n++;
					else
					{
						n = 0;
						m++;
					}
				}
			}
		det = det + s * (a[0][c] * find_det(b, k - 1));
		s = -1 * s;
	}
	return det;
}

bool check_posdef(double A[SIZE][SIZE])
{
	for (int i = 1; i <= SIZE; i++)
	{
		if (find_det(A, i) <= 0)
			return false;
	}
	return true;
}

void show(double A[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << fixed << setprecision(5) << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n\n";
}

void transpose(double A[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (i < j)
			{
				double temp = A[i][j];
				A[i][j] = A[j][i];
				A[j][i] = temp;
			}
}

bool cholev(double A[SIZE][SIZE])
{
	if (!check_sym(A) || !check_posdef(A))
	{
		if (!check_sym(A))
			cout << "Ma tran ko doi xung!" << endl;
		else if (!check_posdef(A)) 
			cout << "Ma tran ko xac dinh duong!" << endl;
		else 
			cout << "Ma tran ko doi xung va ko xac dinh duong!" << endl;
		return false;
	}

	double L[SIZE][SIZE] = { 0 };
	
	for (int j = 0; j < SIZE; j++) 
	{
		for (int i = j; i < SIZE; i++)
		{ 
			double value = A[j][i]; 
			if (i == j) 
			{ 
				for (int k = 0; k < j; k++)
				{ 
					value = value - pow(L[i][k], 2); 
				} 
				L[i][j] = sqrt(value); 
			} 

			if (i != j) 
			{
				for (int k = 0; k < j; k++)
				{
					value = value - L[j][k] * L[i][k];
				}
				L[i][j] = value / L[j][j];
			}
		}
	}
	cout << "Ma tran ban dau: \n";
	show(A);

	cout << "Ma tran L: \n";
	show(L);

	cout << "Ma tran Lt: \n";
	transpose(L);
	show(L);

	return true;
}

int main()
{
	double A[SIZE][SIZE] = { {4,8,6}, {8,8,6}, {6,6,6   } };
	cholev(A); 
	
	return 0;
}