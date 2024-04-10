#include "../main_test.h"
TEST(DeterminantTest, TwoByTwoMatrix) {
  S21Matrix matrix{2, 2};
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  double result = matrix.Determinant();

  double expected = -2;

  EXPECT_EQ(result, expected);
}

// Test determinant of a 3x3 matrix
TEST(DeterminantTest, ThreeByThreeMatrix) {
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

  double result = matrix.Determinant();

  double expected = 0;  // Determinant of this matrix is 0

  EXPECT_EQ(result, expected);
}

// Test determinant of a 4x4 matrix
TEST(DeterminantTest, FourByFourMatrix) {
  S21Matrix matrix{4, 4};
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(0, 3) = 4;
  matrix(1, 0) = 5;
  matrix(1, 1) = 6;
  matrix(1, 2) = 7;
  matrix(1, 3) = 8;
  matrix(2, 0) = 9;
  matrix(2, 1) = 10;
  matrix(2, 2) = 11;
  matrix(2, 3) = 12;
  matrix(3, 0) = 13;
  matrix(3, 1) = 14;
  matrix(3, 2) = 15;
  matrix(3, 3) = 16;

  double result = matrix.Determinant();

  double expected = 0;  // Determinant of this matrix is 0

  EXPECT_EQ(result, expected);
}

// Test determinant of a 1x1 matrix
TEST(DeterminantTest, OneByOneMatrix) {
  S21Matrix matrix{1, 1};
  matrix(0, 0) = 5;

  double result = matrix.Determinant();

  double expected = 5;  // Determinant of a 1x1 matrix is its only element

  EXPECT_EQ(result, expected);
}

TEST(DeterminantTest, notSquareMatrix) {
  S21Matrix matrix{5, 3};

  EXPECT_THROW(matrix.Determinant(), std::logic_error);
}
