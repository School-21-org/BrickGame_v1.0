#include "fsm.h"
typedef void (*action)(params_t *prms);

action fsm_table[7][8] = {
    {spawn, pause_game, terminate, spawn, spawn, spawn, spawn, spawn},
    {NULL, pause_game, terminate, NULL, NULL, NULL, NULL, NULL},
    {NULL, pause_game, terminate, moveleft, moveright, NULL, movedown, rotaite},
    {NULL, pause_game, terminate, moveleft, moveright, NULL, movedown, rotaite},
    {NULL, pause_game, terminate, NULL, NULL, NULL, spawn, NULL},
    {gameover, gameover, terminate, gameover, gameover, NULL, gameover,
     gameover},
    {terminate, terminate, terminate, terminate, terminate, NULL, terminate,
     terminate}};

/**
 * @brief Calls function from the condition matrix, based on user input and
 * figure type and state
 * @param user_action
 * @param game_info
 * @param g_state
 * @param figure
 */
void updateCurrentState(UserAction_t user_action, GameInfo_t *game_info,
                        GameState_t *g_state, Figure_t *figure) {
  params_t prms;
  prms.game_info = game_info;
  prms.figure = figure;
  prms.g_state = g_state;
  prms.user_action = &user_action;
  action act = fsm_table[*g_state][user_action];
  if (act) act(&prms);
  if (*g_state == ATTACHING && check_win_line(&prms)) {
    up_level(game_info);
    check_max_score(&prms);
  }
}

/**
 * @brief Converts user input to user action
 * state
 * @param user_input
 * @returns UserAction_t action
 */
UserAction_t get_signal(int user_input) {
  UserAction_t rc = Start;
  if (user_input == KEY_DOWN)
    rc = Down;
  else if (user_input == KEY_LEFT)
    rc = Left;
  else if (user_input == KEY_RIGHT)
    rc = Right;
  else if (user_input == ESCAPE)
    rc = Terminate;
  else if (user_input == ENTER_KEY)
    rc = Pause;
  else if (user_input == SPACE_KEY)
    rc = Action;
  return rc;
}

/**
 * @brief Spawn figure
 * @param prms params_t structure
 */
void spawn(params_t *prms) {
  prms->figure->type =
      *prms->g_state == START ? I_BLOCK : prms->figure->type_next;
  *prms->g_state = SPAWN;
  prms->figure->type_next = select_figure(prms->figure->type);
  prms->figure->state = state_1;
  prms->figure->y_pos = 0;
  prms->figure->x_pos = 3;
  set_state(prms, fill_figure(prms));
  copy_field(prms);
  clear_field(prms->game_info->next);
}

/**
 * @brief Move figure down
 * @param prms params_t structure
 */
void movedown(params_t *prms) {
  prms->figure->y_pos += 1;
  set_state(prms, fill_figure(prms));
  if (*prms->g_state == SHIFTING) prms->figure->y_pos -= 1;
  copy_field(prms);
  clear_field(prms->game_info->next);
}

/**
 * @brief Move figure right
 * @param prms params_t structure
 */
void moveright(params_t *prms) {
  prms->figure->x_pos += 1;
  set_state(prms, fill_figure(prms));
  if (*prms->g_state == SHIFTING) prms->figure->x_pos -= 1;
  copy_field(prms);
  clear_field(prms->game_info->next);
}

/**
 * @brief Move figure left
 * @param prms params_t structure
 */
void moveleft(params_t *prms) {
  prms->figure->x_pos -= 1;
  set_state(prms, fill_figure(prms));
  if (*prms->g_state == SHIFTING) prms->figure->x_pos += 1;
  copy_field(prms);
  clear_field(prms->game_info->next);
}

/**
 * @brief Rotaites figure
 * @param prms params_t structure
 */
void rotaite(params_t *prms) {
  int state = prms->figure->state;
  if (prms->figure->state == state_4)
    prms->figure->state = state_1;
  else
    prms->figure->state += 1;
  set_state(prms, fill_figure(prms));
  if (*prms->g_state == SHIFTING) prms->figure->state = state;
  copy_field(prms);
  clear_field(prms->game_info->next);
}

/**
 * @brief Sets game stats to initial value
 * @param prms params_t structure
 */
void gameover(params_t *prms) {
  prms->game_info->score = 0;
  prms->game_info->level = 1;
  prms->game_info->speed = 600;
  *prms->g_state = START;
}

/**
 * @brief Sets game state to EXIT_STATE
 * @param prms params_t structure
 */
void terminate(params_t *prms) { *prms->g_state = EXIT_STATE; }

/**
 * @brief Initialize pause
 * @param prms params_t structure
 */
void pause_game(params_t *prms) {
  prms->game_info->pause = 1;
  *prms->g_state = MOVING;
}

/**
 * @brief Sets next game state based on busy status
 * @param prms params_t structure
 * @param busy status - possibility to shift / move / attach
 */
void set_state(params_t *prms, int busy) {
  if (busy == 1)
    *prms->g_state = SHIFTING;
  else if (busy == 2) {
    *prms->g_state = ATTACHING;
  } else if (busy == 3) {
    *prms->g_state = GAMEOVER;
    clear_field(prms->game_info->field);
  } else
    *prms->g_state = MOVING;
}

/**
 * @brief Up level and increase speed
 * @param game_info GameInfo_t structure
 */
void up_level(GameInfo_t *game_info) {
  if (game_info->level < 10 && game_info->score >= 600) {
    game_info->speed = 600 - 50 * (game_info->score / 600);
    game_info->level = 1 + game_info->score / 600;
  }
}

/**
 * @brief Check and write maximum achieved score
 * @param prms params_t structure
 */
void check_max_score(params_t *prms) {
  int max_score = read_max_score();
  if (max_score != -1) {
    if (prms->game_info->score > max_score) {
      write_max_score(prms->game_info->score);
      prms->game_info->high_score = prms->game_info->score;
    }
  } else {
    *prms->g_state = EXIT_STATE;
  }
}