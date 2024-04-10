#include "../main_test.h"

TEST(SumMatrixTest, SumEmptyMatrix) {
  // Create matrices for testing
  S21Matrix matrix1;
  S21Matrix matrix2;

  // Sum matrices
  matrix1 += matrix2;

  // Check if result is an empty matrix
  ASSERT_EQ(matrix1(0, 0), 0);
}

TEST(SumMatrixTest, SumEqualSizeMatrices) {
  // Create matrices for testing
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  // Fill matrices with some values
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  // Sum matrices
  matrix1 += matrix2;

  // Check if result is as expected
  ASSERT_EQ(matrix1(0, 0), 6);
  ASSERT_EQ(matrix1(0, 1), 8);
  ASSERT_EQ(matrix1(1, 0), 10);
  ASSERT_EQ(matrix1(1, 1), 12);
}

TEST(SumMatrixTest, SumDifferentSizeMatrices) {
  // Create matrices for testing
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 3);

  // Sum matrices (should fail due to different sizes)
  ASSERT_ANY_THROW(matrix1 + matrix2);
}

TEST(SumMatrixTest, SumWithEmptyMatrix) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2;

  ASSERT_ANY_THROW(matrix1 + matrix2);
}
