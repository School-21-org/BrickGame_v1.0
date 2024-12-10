CC = gcc
CFLAGS = -Wall -Wextra -Werror -g --std=c11
BACKEND_SOURCE = $(filter-out brick_game/tetris/tetris.c, $(wildcard brick_game/tetris/*.c))
FRONTEND_SOURCE = $(wildcard gui/cli/*.c)
SOURCE_TEST = $(wildcard tests/*.c)
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	# CFLAGS += -DLinux
	GFLAGS = -lcheck -lm -lsubunit
endif

ifeq ($(UNAME), Darwin)
	# CFLAGS += -DDarwin
	GFLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lcheck
endif

all: clean install
	@./launcher

install: s21_tetris_back.a s21_tetris_front.a
	$(CC) $(CFLAGS) brick_game/tetris/tetris.c s21_tetris_back.a s21_tetris_front.a -o launcher -lncurses
	@rm s21_tetris_back.a s21_tetris_front.a

uninstall: clean
	@rm -rf launcher

s21_tetris_back.a:
	$(CC) $(CFLAGS) -c $(BACKEND_SOURCE)
	ar -rc s21_tetris_back.a backend.o fsm_logic.o
	ranlib s21_tetris_back.a
	@rm -rf *.o

s21_tetris_front.a:
	$(CC) $(CFLAGS) -c $(FRONTEND_SOURCE)
	ar -rc s21_tetris_front.a gui.o
	ranlib s21_tetris_front.a
	@rm -rf *.o

test: clean s21_tetris_back.a
	$(CC) $(CFLAGS) $(SOURCE_TEST) s21_tetris_back.a -o test $(GFLAGS)
	./test
	@rm s21_tetris_back.a test

gcov_report: clean
	@$(CC) $(CFLAGS) $(SOURCE_TEST) $(BACKEND_SOURCE) -o test $(GFLAGS) --coverage
	@./test
	@lcov -t "tests" -o tests.info -c -d . -rc lcov_branch_coverage=1 --exclude "$(PWD)/tests/*"
	@genhtml -o report tests.info -rc lcov_branch_coverage=1
	@rm -rf *.gcno *.gcda *.gcov

style: clean
	find . -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -n -style=file:../materials/linters/.clang-format {} \;

clang:
	find . -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -i -style=file:../materials/linters/.clang-format {} \;

clean:
	@rm -rf a.out a.out.dSYM s21_tetris_back.a s21_tetris_front.a tetris.tar launcher *.gcno *.gcda *.gcov test *.info report/

dist:
	tar -cvf tetris.tar brick_game/tetris/ common/ gui/cli/ Makefile

dvi:
	@open docs/finite_state_dgm.png

valgrind_test: clean s21_tetris_back.a
	$(CC) $(CFLAGS) $(SOURCE_TEST) s21_tetris_back.a -o test $(GFLAGS)
	valgrind -s -q --tool=memcheck --leak-check=yes --track-origins=yes --show-leak-kinds=all --verbose --log-file=valgrind_out.txt ./test
	cat valgrind_out.txt
	@rm s21_tetris_back.a test valgrind_out.txt

cppcheck_test:
	cppcheck --enable=all --suppress=missingIncludeSystem brick_game/tetris/*.c brick_game/tetris/*.h common/*.h gui/cli/*.c gui/cli/*.h tests/*.c tests/*.h