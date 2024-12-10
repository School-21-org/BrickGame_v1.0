#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../brick_game/tetris/backend.h"
#include "../brick_game/tetris/fsm.h"

Suite *test_matrix();
Suite *test_fsm();
Suite *test_attaching();
Suite *test_attaching_figure();
Suite *test_move_left();
Suite *test_move_right();
Suite *test_move_left_shift();
Suite *test_move_right_shift();
Suite *test_rotaite();

#endif