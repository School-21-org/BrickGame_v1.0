#include "tetris.h"

int main(void) {
  WIN_INIT(0);
  game_loop();
  endwin();
  return 0;
}

/**
 * @brief main game loop,
 * initializes structures and calls backend and frontent
 */
void game_loop() {
  bool break_flag = TRUE;
  int signal = 0;
  GameInfo_t game_info;
  GameState_t g_state;
  Figure_t figure;
  game_info_init(&game_info);
  print_window(1, &game_info);

  break_flag = start();
  g_state = START;
  signal = 0;
  long long prev_time = current_timestamp();
  while (break_flag) {
    if (signal != ERR || g_state == GAMEOVER) {
      updateCurrentState(get_signal(signal), &game_info, &g_state, &figure);
      print_window(0, &game_info);
    }

    long long current_time = current_timestamp();
    if (g_state != GAMEOVER && current_time > prev_time + game_info.speed) {
      updateCurrentState(Down, &game_info, &g_state, &figure);
      print_window(0, &game_info);
      prev_time = current_time;
    }

    if (g_state == GAMEOVER)
      game_over_loop(&g_state, &game_info);
    else
      print_next_figure(&figure);

    if (game_info.pause) break_flag = pause_state(&game_info);

    if (g_state == EXIT_STATE)
      break_flag = FALSE;
    else
      signal = GET_USER_INPUT;
  }

  mem_free(&game_info);
}

/**
 * @brief start menu loop
 * @return TRUE if ENTER pressed, FALSE if ESC
 */
bool start() {
  bool break_flag = TRUE;
  int signal = 0;
  while (signal != ENTER_KEY && signal != ESCAPE) {
    signal = GET_USER_INPUT;
    if (signal == ENTER_KEY) {
      erase();
    } else if (signal == ESCAPE)
      break_flag = FALSE;
  }
  return break_flag;
}

/**
 * @brief pause loop
 * @param game_info structure GameInfo_t
 * @return TRUE if SPACE is pressed, FALSE if ESC
 */
bool pause_state(GameInfo_t* game_info) {
  bool break_flag = TRUE;

  while (game_info->pause) {
    int signal = ERR;
    print_pause();
    signal = GET_USER_INPUT;
    if (signal == SPACE_KEY || signal == ESCAPE) {
      game_info->pause = 0;
      if (signal == ESCAPE) break_flag = FALSE;
      remove_pause();
    }
  }
  return break_flag;
}

/**
 * @brief game over loop
 * @param g_state game state
 * @param game_info structure GameInfo_t
 */
void game_over_loop(GameState_t* g_state, GameInfo_t* game_info) {
  int signal = 0;
  print_gameover(game_info);
  while (signal != ENTER_KEY && signal != ESCAPE) {
    signal = GET_USER_INPUT;
    if (signal == ESCAPE) {
      *g_state = EXIT_STATE;
    }
  }
}