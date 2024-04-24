#include "Matrix.h"
#include <string>
#include <iostream>
#include <sstream>

Matrix::Matrix(int N) : size(N) {
    data = new int* [size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix() : size(0), data(nullptr) {}

Matrix::Matrix(const Matrix& other) : size(other.size) {
    data = new int* [size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

int Matrix::getSize() const {
    return size;
}

int Matrix::getElement(int i, int j) const {
    return data[i][j];
}

void Matrix::setSize(int N) {
    if (N <= 0) {
        throw std::invalid_argument("Invalid matrix size");
    }
    if (N == size) {
        return;
    }
    int** newData = new int* [N];
    for (int i = 0; i < N; ++i) {
        newData[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            newData[i][j] = 0;
        }
    }
    for (int i = 0; i < std::min(size, N); ++i) {
        for (int j = 0; j < std::min(size, N); ++j) {
            newData[i][j] = data[i][j];
        }
    }
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
    size = N;
    data = newData;
}

void Matrix::setElement(int i, int j, int value) {
    data[i][j] = value;
}

double Matrix::calculateNorm() const {
    double norm = 0.0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            norm += data[i][j] * data[i][j];
        }
    }
    return sqrt(norm);
}

Matrix& Matrix::operator++() {
    setSize(size + 1);
    return *this;
}

Matrix& Matrix::operator--() {
    if (size > 1) {
        setSize(size - 1);
    }
    else {
        throw runtime_error("Invalid matrix size after decrement");
    }
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix oldMatrix(*this);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j]++;
        }
    }
    return oldMatrix;
}

Matrix Matrix::operator--(int) {
    Matrix oldMatrix(*this);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j]--;
        }
    }
    return oldMatrix;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }

    if (size != other.size) {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
        size = other.size;
        initializeMatrix(0);
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrix dimensions mismatch");
        exit(1);
    }
    Matrix result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

bool Matrix::operator==(const Matrix& other) const {
    if (size != other.size) return false;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (data[i][j] != other.data[i][j]) return false;
        }
    }
    return true;
}

Matrix::operator string () const
{
    stringstream ss;
    ss << "Matrix(" << size << "x" << size << "):" << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ss << data[i][j] << " ";
        }
        ss << std::endl;
    }
    return ss.str();
}

void Matrix::initializeMatrix(int initialValue) {
    data = new int* [size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = initialValue;
        }
    }
}

int* Matrix::operator[](int index) {
    if (index < 0  (index) >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const int* Matrix::operator[](int index) const {
    if (index < 0  (index) >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

istream& operator>>(istream& input, Matrix& matrix) {
    for (int i = 0; i < matrix.getSize(); ++i) {
        for (int j = 0; j < matrix.getSize(); ++j) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            input >> matrix.data[i][j];
        }
    }
    return input;
}

ostream& operator<<(ostream& output, const Matrix& matrix) {
    output << string(matrix);
    return output;
}
