#include "../main_test.h"

// Test getter and setter for rows
TEST(GetterSetterTest, Rows) {
  S21Matrix matrix{3, 3};

  // Check initial value
  EXPECT_EQ(matrix.GetRows(), 3);
}

TEST(GetterSetterTest, GetCols) {
  S21Matrix matrix{3, 3};

  // Check initial value
  EXPECT_EQ(matrix.GetCols(), 3);
}

// Test getter and setter for columns
TEST(GetterSetterTest, Cols) {
  S21Matrix matrix{3, 3};

  EXPECT_THROW(matrix.SetCols(-1), std::invalid_argument);
}

// Test getter and setter for rows with resizing
TEST(GetterSetterTest, RowsWithResize) {
  S21Matrix matrix{3, 3};

  // Set invalid value, expect exception
  EXPECT_THROW(matrix.SetRows(0), std::invalid_argument);
}

// Test getter and setter for columns with resizing
TEST(GetterSetterTest, ColsWithResize) {
  S21Matrix matrix{3, 3};

  // Set invalid value, expect exception
  EXPECT_THROW(matrix.SetCols(-1), std::invalid_argument);
}

TEST(GetterSetterTest, SetCols) {
  S21Matrix matrix{3, 3};

  matrix.SetCols(5);
  EXPECT_NO_THROW(matrix(0, 4));
}

TEST(GetterSetterTest, SetRows) {
  S21Matrix matrix{3, 3};

  matrix.SetRows(5);
  EXPECT_NO_THROW(matrix(4, 0));
}
