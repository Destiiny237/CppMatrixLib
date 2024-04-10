#include "../main_test.h"

TEST(EqTest, Equal) {
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
  matrix2(0, 0) = 9;
  matrix2(0, 1) = 8;
  matrix2(0, 2) = 7;
  matrix2(1, 0) = 6;
  matrix2(1, 1) = 5;
  matrix2(1, 2) = 4;
  matrix2(2, 0) = 3;
  matrix2(2, 1) = 2;
  matrix2(2, 2) = 1;

  bool result = (matrix1 == matrix2);
  EXPECT_EQ(result, true);
}

TEST(EqTest, NotEqual) {
  // Create matrices for testing
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  // Fill matrices with different values
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      matrix1(i, j) = i + j;
      matrix2(i, j) = 2 * i + j;
    }
  }

  // Check if matrices are not equal
  ASSERT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(EqTest, DifferentDimensions) {
  // Create matrices for testing
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 3);

  // Fill matrices with some values
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(0, 2) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;
  matrix2(1, 2) = 6;
  matrix2(2, 0) = 7;
  matrix2(2, 1) = 8;
  matrix2(2, 2) = 9;

  // Check if matrices with different dimensions are not equal
  ASSERT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(EqTest, EmptyMatrices) {
  // Create empty matrices for testing
  S21Matrix matrix1;
  S21Matrix matrix2;

  // Check if two empty matrices are equal
  ASSERT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST(EqTest, SingleElementMatrices) {
  // Create matrices with single elements for testing
  S21Matrix matrix1(1, 1);
  S21Matrix matrix2(1, 1);

  // Fill matrices with single element
  matrix1(0, 0) = 5;
  matrix2(0, 0) = 5;

  // Check if matrices with single elements are equal
  ASSERT_TRUE(matrix1.EqMatrix(matrix2));
}