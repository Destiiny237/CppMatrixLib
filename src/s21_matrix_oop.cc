#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : S21Matrix(DEFAULT_ROWS, DEFAULT_COLS) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_{rows}, cols_{cols} {
  matrix_ = new double *[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0.;
    }
  }
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other(i, j);
    }
  }
}

// Move constructor
S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  // Clear 'other'
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

int S21Matrix::GetRows() { return this->rows_; }

int S21Matrix::GetCols() { return this->cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows <= 0)
    throw std::invalid_argument(
        "Size of rows of matrix cannot be zero or negative");

  S21Matrix tmp{rows, this->cols_};

  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      tmp(i, j) = (*this)(i, j);
    }
    for (int j = this->cols_; j < cols_; j++) {
      tmp(i, j) = 0;
    }
  }

  *this = std::move(tmp);
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0)
    throw std::invalid_argument(
        "Size of cols of matrix cannot be zero or negative");

  S21Matrix tmp{this->rows_, cols};

  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      tmp(i, j) = (*this)(i, j);
    }
    for (int j = cols_; j < cols; j++) {
      tmp(i, j) = 0;
    }
  }

  *this = std::move(tmp);
}

S21Matrix::~S21Matrix() { CleanMatrix(); }

void S21Matrix::CleanMatrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i] != nullptr) delete[] matrix_[i];
    }

    delete[] matrix_;
    matrix_ = nullptr;
  }
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (matrix_[i][j] != other(i, j)) return false;
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if ((this->cols_ != other.cols_) || (this->rows_ != other.rows_)) {
    throw std::domain_error("Different dimensions in sum operation");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other(i, j);
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if ((this->cols_ != other.cols_) || (this->rows_ != other.rows_)) {
    throw std::domain_error("Different dimensions in sub operation");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other(i, j);
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (this->cols_ != other.rows_) {
    throw std::logic_error(
        "The number of columns of the first matrix is not equal to the number "
        "of rows of the second matrix.");
  }
  S21Matrix tmp = S21Matrix(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        tmp(i, j) += matrix_[i][k] * other(k, j);
      }
    }
  }
  std::swap(*this, tmp);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result{this->cols_, this->rows_};

  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      result(i, j) = matrix_[j][i];
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (this->cols_ != this->rows_) {
    throw std::logic_error("The matrix is not square");
  }

  double result = 0;
  if (rows_ == 1) return matrix_[0][0];

  if (rows_ == 2)
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];

  for (int j = 0; j < cols_; j++) {
    S21Matrix minor{this->Minor(0, j)};
    double det_minor = minor.Determinant();

    // Алгебраическое дополнение = (-1)^j * matrix[0][j] * det(minor)
    int sign = j % 2 == 0 ? 1 : -1;
    result += sign * matrix_[0][j] * det_minor;
  }

  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (this->cols_ != this->rows_) {
    throw std::logic_error("The matrix is not square");
  }

  S21Matrix result{rows_, cols_};
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < rows_; ++j) {
      S21Matrix minor{this->Minor(i, j)};
      // алгебраическое дополнение (-1)^(i+j) * det(minor)
      int sign = (i + j) % 2 == 0 ? 1 : -1;
      double det_minor = minor.Determinant();
      result(i, j) = sign * det_minor;
    }
  }

  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix result{rows_, cols_};

  S21Matrix comatrix = this->CalcComplements();
  double determinant = this->Determinant();

  if ((determinant < EPS) && (-EPS < determinant)) {
    throw std::logic_error("The determinant of the matrix is 0.");
  }

  double inv_det_A = 1.0 / determinant;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result(i, j) = comatrix(i, j) * inv_det_A;
    }
  }

  return result.Transpose();
}

S21Matrix S21Matrix::Minor(int row, int col) {
  S21Matrix minor{rows_ - 1, cols_ - 1};
  int r = 0;
  for (int i = 0; i < rows_; i++) {
    if (i == row) {
      continue;
    }
    int c = 0;
    for (int j = 0; j < cols_; j++) {
      if (j == col) {
        continue;
      }
      minor.matrix_[r][c] = matrix_[i][j];
      c++;
    }
    r++;
  }

  return minor;
}

double S21Matrix::operator()(int i, int j) const {
  if (i >= this->rows_ || j >= this->cols_)
    throw std::logic_error("Index outside the matrix");
  return matrix_[i][j];
}

double &S21Matrix::operator()(int i, int j) {
  if (i >= this->rows_ || j >= this->cols_)
    throw std::logic_error("Index outside the matrix");
  return matrix_[i][j];
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

S21Matrix S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) {
  S21Matrix firstMatrix(*this);
  bool result = firstMatrix.EqMatrix(other);
  return result;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  S21Matrix temp{other};

  std::swap(rows_, temp.rows_);
  std::swap(cols_, temp.cols_);
  std::swap(matrix_, temp.matrix_);
  return *this;
}
