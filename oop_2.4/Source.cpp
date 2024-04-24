#include <iostream>
#include "Matrix.h"

int main() {
#pragma pack(push, 1)
    std::cout << "Size of Matrix class with pragma pack(1): " << sizeof(Matrix) << " bytes" << std::endl;
#pragma pack(pop)

    Matrix matrix1(3), matrix2(3);
    matrix1[0][0] = 1;
    int element = matrix1[0][0];
    std::cout << "matrix[0][0]: " << element << std::endl;
    std::cout << "Enter elements for matrix1:" << std::endl;
    std::cin >> matrix1;

    std::cout << "Matrix1:" << std::endl;
    std::cout << matrix1 << std::endl;

    std::cout << "Enter elements for matrix2:" << std::endl;
    std::cin >> matrix2;

    std::cout << "matrix2:" << std::endl;
    std::cout << matrix2 << std::endl;

    std::cout << "Matrix1 - matrix2 " << ":" << std::endl;
    std::cout << matrix1 - matrix2 << std::endl;

    std::cout << "Matrix2: \n" << matrix2 << std::endl;
    if (matrix1 == matrix2) {
        std::cout << "Matrix1 is equal to Matrix2" << std::endl;
    }
    else {
        std::cout << "Matrix1 is not equal to Matrix2" << std::endl;
    }

    int norm = matrix1.calculateNorm();
    std::cout << "Norm of matrix1: " << norm << std::endl;

    return 0;
}