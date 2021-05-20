#include "Matrix.h"

Matrix::Matrix(int nRows, int nCols){
    assert(nRows > 0); 
    assert(nCols > 0);
    rows = new int{nRows};
    cols = new int{nCols};
    table = new double*[nRows];
    for(int i{0}; i < nRows; i++){
        table[i] = new double[nCols];
        for(int j{0}; j < nCols; j++){
            table[i][j] = 0;
        }
    }
}

Matrix::Matrix(int nRows) : Matrix(nRows, nRows){
    for(int i{0}; i < nRows; i++){
        table[i][i] = 1;
    }
}

Matrix::Matrix(const Matrix& m) : Matrix(*m.rows, *m.cols){
    for(int i{0}; i < *rows; i++){
        for(int j{0}; j < *cols; j++){
            table[i][j] = m.table[i][j];
        }
    }
}

Matrix Matrix::operator=(Matrix& m){
    swap(rows, m.rows);
    swap(cols, m.cols);
    swap(table, m.table);
    return *this;
}

Matrix Matrix::operator+=(const Matrix& m){
    assert(*rows == *m.rows);
    assert(*cols == *m.cols);
    for(int i{0}; i < *rows; i++){
        for(int j{0}; j < *cols; j++){
            table[i][j] += m.table[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& m) const{
    assert(*rows == *m.rows);
    assert(*cols == *m.cols);
    Matrix newMatrix = Matrix(*rows,*cols);
    for(int i{0}; i < *rows; i++){
        for(int j{0}; j < *cols; j++){
            newMatrix.table[i][j] = table[i][j] + m.table[i][j];
        }
    }
    return newMatrix;
}

Matrix::~Matrix(){
    for(int i{0}; i < *rows; i++){
        delete[] table[i];
        table[i] = nullptr;
    }
    delete[] table;
    delete rows;
    delete cols;
    table = nullptr;
    rows = nullptr;
    cols = nullptr;
}

void Matrix::set(int row, int col, double val){
    table[row][col] = val;
}

double Matrix::get(int row, int col){
    return table[row][col];
}
//double* Matrix::operator[](const Matrix** &m, int index){
//    return 
//}

int Matrix::getRows() const{
    return *this->rows;
}

int Matrix::getCols() const{
    return *this->cols;
}

ostream& operator<<(ostream& os, const Matrix& m){
    double max = 1;
    for(int i{0}; i < *m.rows; i++){
        for(int j{0}; j < *m.cols; j++){
            if(abs(m.table[i][j]) > max){
                max = abs(m.table[i][j]);
            }
        }
    }
    double ww = log10(max);
	int w = round(ww)+2; 
    for(int i{0}; i < *m.rows; i++){
        os << endl;
        for(int j{0}; j < *m.cols; j++){
            os << setw(w) << m.table[i][j];
        }
    }
    os << endl;
    return os;
}

void testMatrix(){
    Matrix mat0 = Matrix(5);
    cout << mat0 << endl;
    Matrix mat1 = Matrix(2,5);
    cout << mat1 << endl;
    Matrix mat2{mat0};
    cout << mat2 << endl;
    mat2 = mat1;
    cout << "mat0: " << mat0.getRows() << endl;
    cout << "mat1: " << mat1.getRows() << endl;
    cout << "mat2: " << mat2.getRows() << endl;

    Matrix A = Matrix(2,2);
    A.set(0,0,1.);
    A.set(0,1,2.);
    A.set(1,0,3.);
    A.set(1,1,4.);
    Matrix B = Matrix(2,2);
    B.set(0,0,4.);
    B.set(0,1,3.);
    B.set(1,0,2.);
    B.set(1,1,1.);
    Matrix C = Matrix(2,2);
    C.set(0,0,1.);
    C.set(0,1,3.);
    C.set(1,0,1.5);
    C.set(1,1,2.);
    cout << "A: " << A << endl
         << "B: " << B << endl
         << "C: " << C << endl;
    A += B + C;
    cout << "--------------\n";
    cout << "A: " << A << endl
         << "B: " << B << endl
         << "C: " << C << endl;
}