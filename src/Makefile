CC = g++
CFLAGS = -Wall -Werror -Wextra -g -std=c++17
GTEST_FLAGS = -lgtest -lgtest_main -pthread
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

MATRIX_SRCS = s21_matrix_oop.cc
TEST_SRCS = Tests/main_test.cc Tests/Functions/equal_test.cc Tests/Functions/sum_test.cc Tests/Functions/transpose_test.cc Tests/Functions/sub_test.cc Tests/Functions/mul_test.cc Tests/Functions/inverse_test.cc Tests/Functions/determinant_test.cc Tests/Functions/get_and_set_test.cc 

all: build

s21_matrix_oop.a: $(MATRIX_SRCS)
	ar rcs $@ $(MATRIX_SRCS)

test: test_runner.out
	./test_runner.out

test_runner.out: $(MATRIX_SRCS) s21_matrix_oop.a
	$(CC) $(CFLAGS) $(TEST_SRCS) $(MATRIX_SRCS) -o test_runner.out $(GTEST_FLAGS)

gcov_report: test
	$(CC) $(GCOV_FLAGS) $(CFLAGS) $(MATRIX_SRCS) $(TEST_SRCS) -o coverage.out $(GTEST_FLAGS)
	./coverage.out
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage_html

valgrind: test_runner.out
	valgrind --tool=memcheck --leak-check=yes ./test_runner.out

clang_check:
	clang-format -style=Google -n $(TEST_SRCS) $(MATRIX_SRCS)

clang_format:
	clang-format -style=Google -i $(TEST_SRCS) $(MATRIX_SRCS)

rebuild: clean build

build:
	$(CC) $(CFLAGS) main.cc $(MATRIX_SRCS) -o matrix.out

clean:
	rm -rf *.out *.a *.gcno *.gcda coverage coverage.info coverage_html output_directory