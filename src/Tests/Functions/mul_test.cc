#include "../main_test.h"

TEST(MulNumberTest, PositiveNumber) {
  S21Matrix matrix{3, 3};
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;

  double num = 2.0;

  matrix *= num;

  S21Matrix expected{3, 3};
  expected(0, 0) = 2;
  expected(0, 1) = 4;
  expected(0, 2) = 6;
  expected(1, 0) = 8;
  expected(1, 1) = 10;
  expected(1, 2) = 12;
  expected(2, 0) = 14;
  expected(2, 1) = 16;
  expected(2, 2) = 18;

  bool temp = (matrix == expected);
  ASSERT_TRUE(temp);
}

// Test multiplication of matrix by negative number
TEST(MulNumberTest, NegativeNumber) {
  S21Matrix matrix{3, 3};
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;

  double num = -2.0;

  S21Matrix result = matrix * num;

  S21Matrix expected{3, 3};
  expected(0, 0) = -2;
  expected(0, 1) = -4;
  expected(0, 2) = -6;
  expected(1, 0) = -8;
  expected(1, 1) = -10;
  expected(1, 2) = -12;
  expected(2, 0) = -14;
  expected(2, 1) = -16;
  expected(2, 2) = -18;

  bool temp = (result == expected);
  ASSERT_TRUE(temp);
}

// Test multiplication of matrix by zero
TEST(MulNumberTest, ZeroNumber) {
  S21Matrix matrix{3, 3};
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;

  double num = 0.0;

  matrix *= num;

  S21Matrix expected{3, 3};
  expected(0, 0) = 0;
  expected(0, 1) = 0;
  expected(0, 2) = 0;
  expected(1, 0) = 0;
  expected(1, 1) = 0;
  expected(1, 2) = 0;
  expected(2, 0) = 0;
  expected(2, 1) = 0;
  expected(2, 2) = 0;

  bool temp = (matrix == expected);
  ASSERT_TRUE(temp);
}

TEST(MulMatrixTest, CompatibleDimensions) {
  S21Matrix matrix1{2, 3};
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 4;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 6;

  S21Matrix matrix2{3, 2};
  matrix2(0, 0) = 7;
  matrix2(0, 1) = 8;
  matrix2(1, 0) = 9;
  matrix2(1, 1) = 10;
  matrix2(2, 0) = 11;
  matrix2(2, 1) = 12;

  S21Matrix result = matrix1;
  result.MulMatrix(matrix2);

  S21Matrix expected{2, 2};
  expected(0, 0) = 58;
  expected(0, 1) = 64;
  expected(1, 0) = 139;
  expected(1, 1) = 154;

  bool temp = (result == expected);
  ASSERT_TRUE(temp);
}

// Test multiplication of matrices with incompatible dimensions
TEST(MulMatrixTest, IncompatibleDimensions) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{4, 3};

  EXPECT_THROW(matrix1 *= matrix2, std::logic_error);
}

// Test multiplication of matrix by zero matrix
TEST(MulMatrixTest, ZeroMatrix) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 2};

  // Expect test to return zero matrix as multiplication by zero matrix results
  // in zero matrix
  S21Matrix result = matrix1 * matrix2;

  S21Matrix expected{2, 2};

  bool temp = (result == expected);
  ASSERT_TRUE(temp);
}
