#include "../main_test.h"

TEST(SubMatrixTest, SameDimensions) {
  S21Matrix matrix1{3, 3};
  matrix1(0, 0) = 9;
  matrix1(0, 1) = 8;
  matrix1(0, 2) = 7;
  matrix1(1, 0) = 6;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 4;
  matrix1(2, 0) = 3;
  matrix1(2, 1) = 2;
  matrix1(2, 2) = 1;

  S21Matrix matrix2{3, 3};
  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(0, 2) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;
  matrix2(1, 2) = 6;
  matrix2(2, 0) = 7;
  matrix2(2, 1) = 8;
  matrix2(2, 2) = 9;

  S21Matrix result = matrix1 - matrix2;

  S21Matrix expected{3, 3};
  expected(0, 0) = 8;
  expected(0, 1) = 6;
  expected(0, 2) = 4;
  expected(1, 0) = 2;
  expected(1, 1) = 0;
  expected(1, 2) = -2;
  expected(2, 0) = -4;
  expected(2, 1) = -6;
  expected(2, 2) = -8;

  bool temp = (result == expected);
  ASSERT_TRUE(temp);
}

// Test subtraction of two matrices with different dimensions
TEST(SubMatrixTest, DifferentDimensions) {
  S21Matrix matrix1{3, 3};
  S21Matrix matrix2{2, 2};

  // Expect test to throw an error because of different dimensions
  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::domain_error);
}

// Test subtraction of two matrices with one being zero matrix
TEST(SubMatrixTest, ZeroMatrix) {
  S21Matrix matrix1{3, 3};
  S21Matrix matrix2{3, 3};

  // Expect test to return matrix1 itself as subtraction of zero matrix won't
  // affect it
  matrix1 -= matrix2;

  bool temp = (matrix1 == matrix1);
  ASSERT_TRUE(temp);
}
