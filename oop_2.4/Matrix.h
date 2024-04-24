// Matrix.h

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Matrix {
private:
    int** data;
    int size;

    void initializeMatrix(int initialValue);

public:
    Matrix(int N);
    Matrix(); 
    Matrix(const Matrix& other);
    ~Matrix();

    int getSize() const;
    int getElement(int i, int j) const;
    void setSize(int N);
    void setElement(int i, int j, int value);

    double calculateNorm() const;

    Matrix& operator ++ ();
    Matrix& operator -- ();
    Matrix operator ++ (int);
    Matrix operator -- (int);

    Matrix& operator=(const Matrix& other); 
    Matrix operator-(const Matrix& other) const;
    bool operator==(const Matrix& other) const; 

    operator string () const;
    int* operator[](int index);
    const int* operator[](int index) const;
    friend istream& operator>>(istream&, Matrix&);
    friend ostream& operator<<(ostream&, const Matrix&);
};