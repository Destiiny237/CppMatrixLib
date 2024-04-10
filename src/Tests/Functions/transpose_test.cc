#include "../main_test.h"

TEST(TransposeTest, SquareMatrix) {
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

  S21Matrix result = matrix.Transpose();

  S21Matrix expected{3, 3};
  expected(0, 0) = 1;
  expected(0, 1) = 4;
  expected(0, 2) = 7;
  expected(1, 0) = 2;
  expected(1, 1) = 5;
  expected(1, 2) = 8;
  expected(2, 0) = 3;
  expected(2, 1) = 6;
  expected(2, 2) = 9;

  bool temp = (result == expected);
  ASSERT_TRUE(temp);
}

// Test transpose of a rectangular matrix
TEST(TransposeTest, RectangularMatrix) {
  S21Matrix matrix{2, 3};
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;

  S21Matrix result = matrix.Transpose();

  S21Matrix expected{3, 2};
  expected(0, 0) = 1;
  expected(0, 1) = 4;
  expected(1, 0) = 2;
  expected(1, 1) = 5;
  expected(2, 0) = 3;
  expected(2, 1) = 6;

  bool temp = (result == expected);
  ASSERT_TRUE(temp);
}

// Test transpose of an empty matrix
TEST(TransposeTest, EmptyMatrix) {
  S21Matrix matrix{0, 0};

  // Expect test to return an empty matrix as transposing an empty matrix
  // results in an empty matrix
  S21Matrix result = matrix.Transpose();

  S21Matrix expected{0, 0};

  bool temp = (result == expected);
  ASSERT_TRUE(temp);
}
