#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <iostream>

#define DEFAULT_ROWS 3
#define DEFAULT_COLS 3

#define EPS 1e-7

class S21Matrix
{
private:
    int rows_, cols_; // Rows and columns
    double **matrix_; // Pointer to the memory where the matrix is allocated

    void CleanMatrix();

public:
    S21Matrix();                       // Default constructor
    S21Matrix(int rows, int cols);     // Parametrize constructor
    S21Matrix(const S21Matrix &other); // Copy constructor
    S21Matrix(S21Matrix &&other);      // Move constructor
    ~S21Matrix();                      // Destructor

    // Accessor and Mutator
    int GetRows();
    int GetCols();
    void SetRows(int rows);
    void SetCols(int cols);

    // Functions
    bool EqMatrix(const S21Matrix &other);

    void SumMatrix(const S21Matrix &other);
    void SubMatrix(const S21Matrix &other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix &other);

    S21Matrix Transpose();
    double Determinant();
    S21Matrix CalcComplements();
    S21Matrix InverseMatrix();

    // Utils for functions
    S21Matrix Minor(int row, int col);

    // Operators
    bool operator==(const S21Matrix &other);
    S21Matrix& operator=(const S21Matrix &other);
    S21Matrix operator+(const S21Matrix &other);
    S21Matrix operator-(const S21Matrix &other);
    S21Matrix operator*(const S21Matrix &other);
    S21Matrix operator*(const double num);

    S21Matrix operator+=(const S21Matrix &other);
    S21Matrix operator-=(const S21Matrix &other);
    S21Matrix operator*=(const S21Matrix &other);
    S21Matrix operator*=(const double num);

    double operator()(int i, int j) const;
    double &operator()(int i, int j);
};

#endif