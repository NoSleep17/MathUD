#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 20

int n;
int lowerTriangle[MAX_SIZE][MAX_SIZE];
int transposedLowerTriangle[MAX_SIZE][MAX_SIZE];
int productMatrix[MAX_SIZE][MAX_SIZE];

void multiplyMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                productMatrix[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int compareMatrices(int A[][MAX_SIZE], int LLT[][MAX_SIZE]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (A[i][j] != LLT[i][j]) return 0;
        }
    }
    return 1;
}

void choleskyDecomposition(int A[][MAX_SIZE]){
    memset(lowerTriangle, 0, sizeof(lowerTriangle));
     for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int sum = 0;
            if (j == i){
                for (int k = 0; k < j; k++)
                    sum += pow(lowerTriangle[j][k], 2);
                lowerTriangle[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (int k = 0; k < j; k++)
                    sum += (lowerTriangle[i][k] * lowerTriangle[j][k]);
                lowerTriangle[i][j] = (A[i][j] - sum) / lowerTriangle[j][j];
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           transposedLowerTriangle[i][j] = lowerTriangle[j][i]; 
        }
    }
}

void displayMatrix(int lowerTriangle[][MAX_SIZE], int transposedLowerTriangle[][MAX_SIZE], int productMatrix[][MAX_SIZE]){
    printf("Lower Triangle\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           printf("%6d ", lowerTriangle[i][j]);
        }
        printf("\n");
    }
    printf("Transpose\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           printf("%6d ", transposedLowerTriangle[i][j]);
        }
        printf("\n");
    }
    printf("Product of Lower Triangle and Transpose\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           printf("%6d ", productMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int A[MAX_SIZE][MAX_SIZE];
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter matrix A\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]); 
        }
    }
    choleskyDecomposition(A);
    multiplyMatrices(lowerTriangle, transposedLowerTriangle);
    displayMatrix(lowerTriangle, transposedLowerTriangle, productMatrix);
    if(compareMatrices(A, productMatrix)) 
        printf("=> A equals LLT\n");
    else 
        printf("=> A is not equal to LLT\n");
    return 0;
}