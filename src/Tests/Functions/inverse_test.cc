#include "../main_test.h"

TEST(InverseMatrixTest, TwoByTwoMatrix) {
  S21Matrix matrix{2, 2};
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix result = matrix.InverseMatrix();

  S21Matrix expected{2, 2};
  expected(0, 0) = -2;
  expected(0, 1) = 1;
  expected(1, 0) = 1.5;
  expected(1, 1) = -0.5;

  bool temp = (result == expected);
  ASSERT_TRUE(temp);
}

// Test inverse of a 3x3 matrix
TEST(InverseMatrixTest, ThreeByThreeMatrix) {
  S21Matrix matrix{3, 3};
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;

  matrix(1, 0) = 0;
  matrix(1, 1) = 1;
  matrix(1, 2) = 4;

  matrix(2, 0) = 5;
  matrix(2, 1) = 6;
  matrix(2, 2) = 0;

  S21Matrix expected{3, 3};
  expected(0, 0) = -24;
  expected(0, 1) = 18;
  expected(0, 2) = 5;

  expected(1, 0) = 20;
  expected(1, 1) = -15;
  expected(1, 2) = -4;

  expected(2, 0) = -5;
  expected(2, 1) = 4;
  expected(2, 2) = 1;

  bool temp = (matrix.InverseMatrix() == expected);
  ASSERT_TRUE(temp);
}

// Test inverse of a 4x4 matrix
TEST(InverseMatrixTest, FourByFourMatrix) {
  S21Matrix matrix{4, 4};
  matrix(0, 0) = 4;
  matrix(0, 1) = 3;
  matrix(0, 2) = 2;
  matrix(0, 3) = 1;
  matrix(1, 0) = 3;
  matrix(1, 1) = 2;
  matrix(1, 2) = 1;
  matrix(1, 3) = 4;
  matrix(2, 0) = 2;
  matrix(2, 1) = 1;
  matrix(2, 2) = 4;
  matrix(2, 3) = 3;
  matrix(3, 0) = 1;
  matrix(3, 1) = 4;
  matrix(3, 2) = 3;
  matrix(3, 3) = 2;

  S21Matrix result = matrix.InverseMatrix();

  S21Matrix expected{4, 4};
  expected(0, 0) = 0.275;
  expected(0, 1) = 0.025;
  expected(0, 2) = 0.025;
  expected(0, 3) = -0.225;
  expected(1, 0) = 0.025;
  expected(1, 1) = 0.025;
  expected(1, 2) = -0.225;
  expected(1, 3) = 0.275;
  expected(2, 0) = 0.025;
  expected(2, 1) = -0.225;
  expected(2, 2) = 0.275;
  expected(2, 3) = 0.025;
  expected(3, 0) = -0.225;
  expected(3, 1) = 0.275;
  expected(3, 2) = 0.025;
  expected(3, 3) = 0.025;

  bool temp = (result == expected);
  ASSERT_TRUE(temp);
}

TEST(InverseMatrixTest, ZeroDeterminant) {
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

  EXPECT_THROW(matrix.InverseMatrix(), std::logic_error);
}

TEST(InverseMatrixTest, notSquareMatrix) {
  S21Matrix matrix{4, 3};

  EXPECT_THROW(matrix.InverseMatrix(), std::logic_error);
}