#pragma once
#include <iostream>
#include <sstream> 
#include <iomanip>
#include <cassert>
#include <cmath>
#include <utility>

using namespace std;

class Matrix{
private:
    int* rows;
    int* cols;
    double** table;
public:
    Matrix(int nRows, int nCols);
    explicit Matrix(int nRows);
    Matrix(const Matrix& m);
    Matrix operator=(Matrix& m);
    Matrix operator+=(const Matrix& m);
    Matrix operator+(const Matrix& m) const;
    ~Matrix();
    void set(int row, int col, double val);
    double get(int row, int col);
    //double* operator[](const Matrix &m, int index);
    int getRows() const;
    int getCols() const;
    friend ostream& operator<<(ostream& os, const Matrix& m);
};

void testMatrix();