#include "../main_test.h"

TEST(BracketsTest, OutsideTheMatrix_1)
{
    S21Matrix matrix {5, 5};
    EXPECT_THROW(matrix(5, 5), std::logic_error);
}

TEST(BracketsTest, OutsideTheMatrix_2)
{
    S21Matrix matrix {5, 5};
    EXPECT_THROW(matrix(6, 2), std::logic_error);
}