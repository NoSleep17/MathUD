#include <iostream>
#include <cmath>

const double EPSILON = 1e-10;

void svd(const double A[3][3], double U[3][3], double S[3], double V[3][3]) {
    // Chuyển vị của A
    double AT[3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            AT[j][i] = A[i][j];
    // A * AT
    double C[3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < 3; ++k)
                C[i][j] += A[i][k] * AT[k][j];
        }

    // Giá trị riêng và vector riêng của C
    double eigenvalues[3];
    double eigenvectors[3][3];
    // Thực hiện phân rã giá trị riêng (có thể sử dụng thư viện cho bước này)
    // Tính giá trị đơn và cập nhật ma trận U và V
    for (int i = 0; i < 3; ++i) {
        S[i] = std::sqrt(std::max(0.0, eigenvalues[i]));
        // Cập nhật ma trận U và V
        for (int j = 0; j < 3; ++j) {
            U[j][i] = eigenvectors[j][i];
            V[j][i] = AT[j][i];
        }
    }
}

int main() {
    double A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double U[3][3], S[3], V[3][3];
    // Thực hiện phân rã SVD
    svd(A, U, S, V);
    std::cout << "Giá trị đơn:\n";
    for (int i = 0; i < 3; ++i)
        std::cout << S[i] << " ";
    std::cout << "\n\n";

    std::cout << "Vector riêng trái:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            std::cout << U[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";

    std::cout << "Vector rieng phai:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            std::cout << V[i][j] << " ";
        std::cout << "\n";
    }
    return 0;
}
