#ifndef GUI_H
#define GUI_H
#include <ncurses.h>

#include "../../common/defines.h"
#include "../../common/objects.h"

#define WIN_INIT(time)    \
  {                       \
    initscr();            \
    noecho();             \
    curs_set(0);          \
    keypad(stdscr, TRUE); \
    timeout(time);        \
    start_color();        \
    init_pair(1, 0, 0);   \
    init_pair(2, 7, 7);   \
    init_pair(3, 0, 3);   \
    bkgd(COLOR_PAIR(3));  \
  }

#define GET_USER_INPUT getch()

#define BOARDS_BEGIN 2

#define MVADDCH(y, x, c) mvaddch(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), c);
#define MVPRINTW(y, x, ...) \
  mvprintw(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), __VA_ARGS__);

void print_window(int start, GameInfo_t *game_info);
void print_overlay(int start);
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void print_playground(const GameInfo_t *game_info);
void print_stats(GameInfo_t *game_info);
void print_gameover(GameInfo_t *game_info);
void print_next_figure(const Figure_t *figure);
void print_pause();
void remove_pause();

#endif