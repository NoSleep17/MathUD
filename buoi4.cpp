#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// Function to initialize a matrix with zeros
void initializeMatrix(int matrix[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

// Function to perform Cholesky Decomposition
void performCholeskyDecomposition(int matrix[][MAX], int lower[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int sum = 0;

            if (j == i) {
                for (int k = 0; k < j; k++)
                    sum += pow(lower[j][k], 2);
                lower[j][j] = sqrt(matrix[j][j] - sum);
            } else {
                for (int k = 0; k < j; k++)
                    sum += (lower[i][k] * lower[j][k]);
                lower[i][j] = (matrix[i][j] - sum) / lower[j][j];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(6) << matrix[i][j] << "\t";
        cout << endl;
    }
}

// Function to perform Cholesky Decomposition and display results
void Cholesky_Decomposition(int matrix[][MAX], int n) {
    int lower[MAX][MAX];
    initializeMatrix(lower, n);

    performCholeskyDecomposition(matrix, lower, n);

    // Displaying Lower Triangular and its Transpose
    cout << setw(6) << " Lower Triangular"
         << setw(30) << "Transpose" << endl;

for (int i = 0; i < n; i++) {
     
    // Lower Triangular
    for (int j = 0; j < n; j++)
        cout << setw(6) << lower[i][j] << "\t";
    cout << "\t";
     
    // Transpose of Lower Triangular
    for (int j = 0; j < n; j++)
        cout << setw(6) << lower[j][i] << "\t";
    cout << endl;
}
}

// Driver Code
int main() {
    int n = 3;
    int matrix[][MAX] = {{4, 12, -16},
                         {12, 37, -43},
                         {-16, -43, 98}};
    Cholesky_Decomposition(matrix, n);
    return 0;
}