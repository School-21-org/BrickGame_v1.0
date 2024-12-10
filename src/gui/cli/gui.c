#include "gui.h"

/**
 * @brief Prints game overlay
 * @param start 1/0 to print additional info
 */
void print_overlay(int start) {
  print_rectangle(1, 3, P_FIELD_WIDTH * 4 + 3,
                  P_FIELD_WIDTH * 4 + POINTS_WIDTH + 9);
  print_rectangle(4, 6, P_FIELD_WIDTH * 4 + 3,
                  P_FIELD_WIDTH * 4 + POINTS_WIDTH + 9);
  print_rectangle(7, 9, P_FIELD_WIDTH * 4 + 3,
                  P_FIELD_WIDTH * 4 + POINTS_WIDTH + 9);
  print_rectangle(10, 16, P_FIELD_WIDTH * 4 + 3,
                  P_FIELD_WIDTH * 4 + POINTS_WIDTH + 9);

  MVPRINTW(2, P_FIELD_WIDTH * 4 + 5, "LEVEL");
  MVPRINTW(5, P_FIELD_WIDTH * 4 + 5, "SCORE");
  MVPRINTW(8, P_FIELD_WIDTH * 4 + 5, "MAX SCORE");
  MVPRINTW(11, P_FIELD_WIDTH * 4 + 7, "NEXT FIGURE");
  MVPRINTW(11, P_FIELD_WIDTH * 4 + 7, "NEXT FIGURE");
  if (!start) {
    MVPRINTW(18, P_FIELD_WIDTH * 4 + 2, "PRESS ENTER TO -PAUSE-");
    MVPRINTW(20, P_FIELD_WIDTH * 4 + 2, "SPACE - ROTATE FIGURE");
    MVPRINTW(22, P_FIELD_WIDTH * 4 + 2, "ARROWS - MOVE FIGURE");
  }
  if (start) {
    MVPRINTW(22, P_FIELD_WIDTH * 4 + 2, "PRESS ENTER TO START");
    MVPRINTW(24, P_FIELD_WIDTH * 4 + 2, "PRESS ESCAPE TO EXIT");
  }
}

/**
 * @brief Prints rectangle boarders
 * @param top_y
 * @param bottom_y
 * @param left_x
 * @param right_x
 */
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x) {
  MVADDCH(top_y, left_x, ACS_ULCORNER);
  int i = left_x + 1;
  for (; i < right_x; i++) {
    MVADDCH(top_y, i, ACS_HLINE);
  }
  MVADDCH(top_y, i, ACS_URCORNER);
  for (int j = top_y + 1; j < bottom_y; j++) {
    MVADDCH(j, left_x, ACS_VLINE);
    MVADDCH(j, right_x, ACS_VLINE);
  }
  MVADDCH(bottom_y, left_x, ACS_LLCORNER);
  i = left_x + 1;
  for (; i < right_x; i++) MVADDCH(bottom_y, i, ACS_HLINE);
  MVADDCH(bottom_y, i, ACS_LRCORNER);
}

/**
 * @brief Prints game statistics
 * @param game_info GameInfo_t structure
 */
void print_stats(GameInfo_t *game_info) {
  MVPRINTW(2, P_FIELD_WIDTH * 4 + 16, "%d", game_info->level);
  MVPRINTW(5, P_FIELD_WIDTH * 4 + 16, "%d", game_info->score);
  MVPRINTW(8, P_FIELD_WIDTH * 4 + 16, "%d", game_info->high_score);
}

/**
 * @brief Prints game field
 * @param game_info GameInfo_t structure
 */
void print_playground(const GameInfo_t *game_info) {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      int y = 3 + i;
      int x = 6 + j;
      if (j != 0) x += 2 * (x - 6);
      if (i != 0) y += (y - 3);
      if (game_info->field[i][j]) {
        attron(COLOR_PAIR(1));
        mvprintw(y, x, "  ");
        attroff(COLOR_PAIR(1));
      } else {
        attron(COLOR_PAIR(2));
        mvprintw(y, x, "  ");
        attroff(COLOR_PAIR(2));
      }
    }
  }
}

/**
 * @brief Prints game over info
 * @param game_info GameInfo_t structure
 */
void print_gameover(GameInfo_t *game_info) {
  MVPRINTW(26, P_FIELD_WIDTH * 4 + 1, "GAME OVER");
  MVPRINTW(28, P_FIELD_WIDTH * 4 + 1, "YOU SCORE IS %d", game_info->score);
  MVPRINTW(30, P_FIELD_WIDTH * 4 + 1, "PRESS ENTER TO TRY AGAIN");
  MVPRINTW(32, P_FIELD_WIDTH * 4 + 1, "PRESS ESCAPE TO EXIT");
}

/**
 * @brief Prints next figure
 * @param figure
 */
void print_next_figure(const Figure_t *figure) {
  if (figure) {
    attron(COLOR_PAIR(1));
    switch (figure->type_next) {
      case I_BLOCK:
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 7, "  ");
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 10, "  ");
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 13, "  ");
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 16, "  ");
        break;
      case J_BLOCK:
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 8, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 8, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 11, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 14, "  ");
        break;
      case L_BLOCK:
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 14, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 8, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 11, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 14, "  ");
        break;
      case O_BLOCK:
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 9, "  ");
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 12, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 9, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 12, "  ");
        break;
      case S_BLOCK:
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 11, "  ");
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 14, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 8, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 11, "  ");
        break;
      case T_BLOCK:
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 11, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 8, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 11, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 14, "  ");
        break;
      case Z_BLOCK:
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 8, "  ");
        MVPRINTW(13, P_FIELD_WIDTH * 4 + 11, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 11, "  ");
        MVPRINTW(15, P_FIELD_WIDTH * 4 + 14, "  ");
        break;
      default:
        break;
    }
    attroff(COLOR_PAIR(1));
  }
}

/**
 * @brief Prints pause info
 */
void print_pause() {
  MVPRINTW(32, P_FIELD_WIDTH * 4 + 1, "PRESS SPACE TO CONTINUE");
  attron(COLOR_PAIR(1));
  mvprintw(26, P_FIELD_WIDTH * 4 + 11, "  ");
  mvprintw(27, P_FIELD_WIDTH * 4 + 11, "  ");
  mvprintw(28, P_FIELD_WIDTH * 4 + 11, "  ");
  mvprintw(29, P_FIELD_WIDTH * 4 + 11, "  ");
  mvprintw(30, P_FIELD_WIDTH * 4 + 11, "  ");

  mvprintw(26, P_FIELD_WIDTH * 4 + 16, "  ");
  mvprintw(27, P_FIELD_WIDTH * 4 + 16, "  ");
  mvprintw(28, P_FIELD_WIDTH * 4 + 16, "  ");
  mvprintw(29, P_FIELD_WIDTH * 4 + 16, "  ");
  mvprintw(30, P_FIELD_WIDTH * 4 + 16, "  ");
  attroff(COLOR_PAIR(1));
}

/**
 * @brief Removes pause info
 */
void remove_pause() {
  MVPRINTW(32, P_FIELD_WIDTH * 4 + 1, "                       ");
  attron(COLOR_PAIR(3));
  mvprintw(26, P_FIELD_WIDTH * 4 + 11, "  ");
  mvprintw(27, P_FIELD_WIDTH * 4 + 11, "  ");
  mvprintw(28, P_FIELD_WIDTH * 4 + 11, "  ");
  mvprintw(29, P_FIELD_WIDTH * 4 + 11, "  ");
  mvprintw(30, P_FIELD_WIDTH * 4 + 11, "  ");

  mvprintw(26, P_FIELD_WIDTH * 4 + 16, "  ");
  mvprintw(27, P_FIELD_WIDTH * 4 + 16, "  ");
  mvprintw(28, P_FIELD_WIDTH * 4 + 16, "  ");
  mvprintw(29, P_FIELD_WIDTH * 4 + 16, "  ");
  mvprintw(30, P_FIELD_WIDTH * 4 + 16, "  ");
  attron(COLOR_PAIR(3));
}

/**
 * @brief Prints window (calls overlay, playground, stats)
 * @param start 1/0 to print additional info
 * @param game_info GameInfo_t structure
 */
void print_window(int start, GameInfo_t *game_info) {
  erase();
  print_overlay(start);
  print_playground(game_info);
  print_stats(game_info);
}