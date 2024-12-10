#include "backend.h"

/**
 * @brief Initialize game_info structure
 * @param game_info GameInfo_t structure
 */
void game_info_init(GameInfo_t *game_info) {
  game_info->level = 1;
  game_info->score = 0;
  game_info->high_score = read_max_score();
  game_info->speed = SPEED;
  game_info->pause = 0;
  field_memory_allocation(game_info);
}

/**
 * @brief Allocates memory for matrix fields
 * @param game_info GameInfo_t structure
 * @returns 1 if allocation failed, 0 in case of success
 */
int field_memory_allocation(GameInfo_t *game_info) {
  int mem_error = SUCCESS;
  game_info->field = calloc(20, sizeof(double *));
  if (game_info->field) {
    for (int i = 0; i < 20 && mem_error == SUCCESS; i++) {
      game_info->field[i] = calloc(10, sizeof(double));
      if (!game_info->field[i]) mem_error = ERROR;
    }
  } else {
    mem_error = ERROR;
  }
  if (!mem_error) {
    game_info->next = calloc(20, sizeof(double *));
    if (game_info->next) {
      for (int i = 0; i < 20 && mem_error == SUCCESS; i++) {
        game_info->next[i] = calloc(10, sizeof(double));
        if (!game_info->next[i]) mem_error = ERROR;
      }
    } else {
      mem_error = ERROR;
    }
  }
  return mem_error;
}

/**
 * @brief Frees memory for matrix fields
 * @param game_info GameInfo_t structure
 */
void mem_free(GameInfo_t *game_info) {
  if (game_info->field) {
    for (int i = 0; i < 20; i++) {
      free(game_info->field[i]);
    }
    free(game_info->field);
  }
  if (game_info->next) {
    for (int i = 0; i < 20; i++) {
      free(game_info->next[i]);
    }
    free(game_info->next);
  }
}

/**
 * @brief Calculates time in miliseconds
 * @returns current miliseconds of the day
 */
long long current_timestamp() {
  struct timeval te;
  gettimeofday(&te, NULL);
  long long miliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
  return miliseconds;
}

/**
 * @brief Randomly selects the next figure
 * @param figure
 * @returns next figure type
 */
figures select_figure(figures figure) {
  int n = 0;
  srand(time(NULL));
  n = rand() % 6;
  if (rand() % 2 == 0 && n == 0) n = 6;
  if (n == (int)figure) n = rand() % 6;
  return (figures)n;
}

/**
 * @brief Select figure to fill
 * @param prms params_t structure
 * @returns
 * 0 - free to move,
 * 1 - shifting,
 * 2 - attaching,
 * 3 - gameover,
 */
int fill_figure(params_t *prms) {
  int busy = 0;
  switch (prms->figure->type) {
    case I_BLOCK:
      busy = fill_i_block(prms);
      break;
    case J_BLOCK:
      busy = fill_j_block(prms);
      break;
    case L_BLOCK:
      busy = fill_l_block(prms);
      break;
    case O_BLOCK:
      busy = fill_o_block(prms);
      break;
    case S_BLOCK:
      busy = fill_s_block(prms);
      break;
    case T_BLOCK:
      busy = fill_t_block(prms);
      break;
    case Z_BLOCK:
      busy = fill_z_block(prms);
      break;
    default:
      break;
  }
  return busy;
}

/**
 * @brief Calculates coordinates for the next position of I block
 * @param prms params_t structure
 * @returns
 * 0 - free to move,
 * 1 - shifting,
 * 2 - attaching,
 * 3 - gameover,
 */
int fill_i_block(params_t *prms) {
  coordinates_t cdnts;
  int busy = 0;
  switch (prms->figure->state) {
    case state_1:
      cdnts.x1 = prms->figure->x_pos;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 2;
      cdnts.x4 = prms->figure->x_pos + 3;
      cdnts.y1 = prms->figure->y_pos + 1;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 1;
      break;
    case state_2:
      cdnts.x1 = prms->figure->x_pos + 2;
      cdnts.x2 = prms->figure->x_pos + 2;
      cdnts.x3 = prms->figure->x_pos + 2;
      cdnts.x4 = prms->figure->x_pos + 2;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 2;
      cdnts.y4 = prms->figure->y_pos + 3;
      break;
    case state_3:
      cdnts.x1 = prms->figure->x_pos;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 2;
      cdnts.x4 = prms->figure->x_pos + 3;
      cdnts.y1 = prms->figure->y_pos + 2;
      cdnts.y2 = prms->figure->y_pos + 2;
      cdnts.y3 = prms->figure->y_pos + 2;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    case state_4:
      cdnts.x1 = prms->figure->x_pos + 1;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 1;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 2;
      cdnts.y4 = prms->figure->y_pos + 3;
      break;
    default:
      break;
  }
  if ((busy = check_figure(prms, &cdnts)) == 0) fill_coordinates(prms, &cdnts);
  return busy;
}

/**
 * @brief Calculates coordinates for the next position of J block
 * @param prms params_t structure
 * @returns
 * 0 - free to move,
 * 1 - shifting,
 * 2 - attaching,
 * 3 - gameover,
 */
int fill_j_block(params_t *prms) {
  coordinates_t cdnts;
  int busy = 0;
  switch (prms->figure->state) {
    case state_1:
      cdnts.x1 = prms->figure->x_pos;
      cdnts.x2 = prms->figure->x_pos;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 2;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 1;
      break;
    case state_2:
      cdnts.x1 = prms->figure->x_pos + 2;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 1;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    case state_3:
      cdnts.x1 = prms->figure->x_pos;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 2;
      cdnts.x4 = prms->figure->x_pos + 2;
      cdnts.y1 = prms->figure->y_pos + 1;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    case state_4:
      cdnts.x1 = prms->figure->x_pos + 1;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 2;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    default:
      break;
  }
  if ((busy = check_figure(prms, &cdnts)) == 0) fill_coordinates(prms, &cdnts);
  return busy;
}

/**
 * @brief Calculates coordinates for the next position of L block
 * @param prms params_t structure
 * @returns
 * 0 - free to move,
 * 1 - shifting,
 * 2 - attaching,
 * 3 - gameover,
 */
int fill_l_block(params_t *prms) {
  coordinates_t cdnts;
  int busy = 0;
  switch (prms->figure->state) {
    case state_1:
      cdnts.x1 = prms->figure->x_pos + 2;
      cdnts.x2 = prms->figure->x_pos;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 2;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 1;
      break;
    case state_2:
      cdnts.x1 = prms->figure->x_pos + 1;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 2;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 2;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    case state_3:
      cdnts.x1 = prms->figure->x_pos;
      cdnts.x2 = prms->figure->x_pos;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 2;
      cdnts.y1 = prms->figure->y_pos + 2;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 1;
      break;
    case state_4:
      cdnts.x1 = prms->figure->x_pos;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 1;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    default:
      break;
  }
  if ((busy = check_figure(prms, &cdnts)) == 0) fill_coordinates(prms, &cdnts);
  return busy;
}

/**
 * @brief Calculates coordinates for the next position of O block
 * @param prms params_t structure
 * @returns
 * 0 - free to move,
 * 1 - shifting,
 * 2 - attaching,
 * 3 - gameover,
 */
int fill_o_block(params_t *prms) {
  coordinates_t cdnts;
  int busy = 0;
  cdnts.x1 = prms->figure->x_pos + 1;
  cdnts.x2 = prms->figure->x_pos + 2;
  cdnts.x3 = prms->figure->x_pos + 1;
  cdnts.x4 = prms->figure->x_pos + 2;
  cdnts.y1 = prms->figure->y_pos;
  cdnts.y2 = prms->figure->y_pos;
  cdnts.y3 = prms->figure->y_pos + 1;
  cdnts.y4 = prms->figure->y_pos + 1;
  if ((busy = check_figure(prms, &cdnts)) == 0) fill_coordinates(prms, &cdnts);
  return busy;
}

/**
 * @brief Calculates coordinates for the next position of S block
 * @param prms params_t structure
 * @returns
 * 0 - free to move,
 * 1 - shifting,
 * 2 - attaching,
 * 3 - gameover,
 */
int fill_s_block(params_t *prms) {
  coordinates_t cdnts;
  int busy = 0;
  switch (prms->figure->state) {
    case state_1:
      cdnts.x1 = prms->figure->x_pos + 1;
      cdnts.x2 = prms->figure->x_pos + 2;
      cdnts.x3 = prms->figure->x_pos;
      cdnts.x4 = prms->figure->x_pos + 1;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 1;
      break;
    case state_2:
      cdnts.x1 = prms->figure->x_pos + 1;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 2;
      cdnts.x4 = prms->figure->x_pos + 2;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    case state_3:
      cdnts.x1 = prms->figure->x_pos;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 2;
      cdnts.y1 = prms->figure->y_pos + 2;
      cdnts.y2 = prms->figure->y_pos + 2;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 1;
      break;
    case state_4:
      cdnts.x1 = prms->figure->x_pos;
      cdnts.x2 = prms->figure->x_pos;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 1;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    default:
      break;
  }
  if ((busy = check_figure(prms, &cdnts)) == 0) fill_coordinates(prms, &cdnts);
  return busy;
}

/**
 * @brief Calculates coordinates for the next position of T block
 * @param prms params_t structure
 * @returns
 * 0 - free to move,
 * 1 - shifting,
 * 2 - attaching,
 * 3 - gameover,
 */
int fill_t_block(params_t *prms) {
  coordinates_t cdnts;
  int busy = 0;
  switch (prms->figure->state) {
    case state_1:
      cdnts.x1 = prms->figure->x_pos + 1;
      cdnts.x2 = prms->figure->x_pos;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 2;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 1;
      break;
    case state_2:
      cdnts.x1 = prms->figure->x_pos + 1;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 2;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 2;
      cdnts.y4 = prms->figure->y_pos + 1;
      break;
    case state_3:
      cdnts.x1 = prms->figure->x_pos;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 2;
      cdnts.x4 = prms->figure->x_pos + 1;
      cdnts.y1 = prms->figure->y_pos + 1;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    case state_4:
      cdnts.x1 = prms->figure->x_pos;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 1;
      cdnts.y1 = prms->figure->y_pos + 1;
      cdnts.y2 = prms->figure->y_pos;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    default:
      break;
  }
  if ((busy = check_figure(prms, &cdnts)) == 0) fill_coordinates(prms, &cdnts);
  return busy;
}

/**
 * @brief Calculates coordinates for the next position of Z block
 * @param prms params_t structure
 * @returns
 * 0 - free to move,
 * 1 - shifting,
 * 2 - attaching,
 * 3 - gameover,
 */
int fill_z_block(params_t *prms) {
  coordinates_t cdnts;
  int busy = 0;
  switch (prms->figure->state) {
    case state_1:
      cdnts.x1 = prms->figure->x_pos + 1;
      cdnts.x2 = prms->figure->x_pos + 2;
      cdnts.x3 = prms->figure->x_pos;
      cdnts.x4 = prms->figure->x_pos + 1;
      cdnts.y1 = prms->figure->y_pos + 1;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos;
      cdnts.y4 = prms->figure->y_pos;
      break;
    case state_2:
      cdnts.x1 = prms->figure->x_pos + 2;
      cdnts.x2 = prms->figure->x_pos + 2;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 1;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    case state_3:
      cdnts.x1 = prms->figure->x_pos;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos + 1;
      cdnts.x4 = prms->figure->x_pos + 2;
      cdnts.y1 = prms->figure->y_pos + 1;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 2;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    case state_4:
      cdnts.x1 = prms->figure->x_pos + 1;
      cdnts.x2 = prms->figure->x_pos + 1;
      cdnts.x3 = prms->figure->x_pos;
      cdnts.x4 = prms->figure->x_pos;
      cdnts.y1 = prms->figure->y_pos;
      cdnts.y2 = prms->figure->y_pos + 1;
      cdnts.y3 = prms->figure->y_pos + 1;
      cdnts.y4 = prms->figure->y_pos + 2;
      break;
    default:
      break;
  }
  if ((busy = check_figure(prms, &cdnts)) == 0) fill_coordinates(prms, &cdnts);
  return busy;
}

/**
 * @brief Checks possibility to move block
 * @param prms params_t structure
 * @param crdnts coordinates_t structure
 * @returns
 * 0 - free to move,
 * 1 - shifting,
 * 2 - attaching,
 * 3 - gameover,
 */
int check_figure(params_t *prms, const coordinates_t *crdnts) {
  int busy = 0;
  if (crdnts->x1 < 0 || crdnts->x1 > 9 || crdnts->x2 < 0 || crdnts->x2 > 9 ||
      crdnts->x3 < 0 || crdnts->x3 > 9 || crdnts->x4 < 0 || crdnts->x4 > 9)
    busy = 1;
  if (crdnts->y1 > 19 || crdnts->y2 > 19 || crdnts->y3 > 19 ||
      crdnts->y4 > 19) {
    busy = 2;
    if (*prms->user_action == Action && prms->figure->type == I_BLOCK &&
        prms->figure->state == state_2 && crdnts->y4 == 20)
      busy = 1;
  }
  if (!busy && *prms->g_state != SPAWN) temporary_fill_block(prms, 0);
  if (!busy) busy = check_figures_overlay(prms, crdnts);
  if (busy) temporary_fill_block(prms, 1);

  return busy;
}

/**
 * @brief Additional check of possibility to move block
 * @param prms params_t structure
 * @param crdnts coordinates_t structure
 * @returns
 * 0 - free to move,
 * 1 - shifting,
 * 2 - attaching,
 * 3 - gameover,
 */
int check_figures_overlay(params_t *prms, const coordinates_t *crdnts) {
  int busy = 0;
  prms->game_info->next[crdnts->y1][crdnts->x1] = 1;
  prms->game_info->next[crdnts->y2][crdnts->x2] = 1;
  prms->game_info->next[crdnts->y3][crdnts->x3] = 1;
  prms->game_info->next[crdnts->y4][crdnts->x4] = 1;

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      if (prms->game_info->field[i][j] && prms->game_info->next[i][j]) {
        if (*prms->user_action == Down && *prms->g_state != SPAWN) {
          busy = 2;
        } else if (*prms->user_action == Left || *prms->user_action == Right ||
                   *prms->user_action == Action) {
          busy = 1;
        } else
          busy = 3;
      }
    }
  }
  prms->game_info->next[crdnts->y1][crdnts->x1] = 0;
  prms->game_info->next[crdnts->y2][crdnts->x2] = 0;
  prms->game_info->next[crdnts->y3][crdnts->x3] = 0;
  prms->game_info->next[crdnts->y4][crdnts->x4] = 0;
  return busy;
}

/**
 * @brief Fills or removes figure from field
 * @param prms params_t structure
 * @param value 1 or 0 depending on what value to fill in matrix
 */
void temporary_fill_block(params_t *prms, int value) {
  prms->game_info->field[prms->figure->y1][prms->figure->x1] = value;
  prms->game_info->field[prms->figure->y2][prms->figure->x2] = value;
  prms->game_info->field[prms->figure->y3][prms->figure->x3] = value;
  prms->game_info->field[prms->figure->y4][prms->figure->x4] = value;
}

/**
 * @brief Fills next figure and saves its coordinates
 * @param prms params_t structure
 * @param cdnts coordinates_t structure
 */
void fill_coordinates(params_t *prms, const coordinates_t *cdnts) {
  prms->game_info->next[cdnts->y1][cdnts->x1] = 1;
  prms->game_info->next[cdnts->y2][cdnts->x2] = 1;
  prms->game_info->next[cdnts->y3][cdnts->x3] = 1;
  prms->game_info->next[cdnts->y4][cdnts->x4] = 1;
  prms->figure->x1 = cdnts->x1;
  prms->figure->x2 = cdnts->x2;
  prms->figure->x3 = cdnts->x3;
  prms->figure->x4 = cdnts->x4;
  prms->figure->y1 = cdnts->y1;
  prms->figure->y2 = cdnts->y2;
  prms->figure->y3 = cdnts->y3;
  prms->figure->y4 = cdnts->y4;
}

/**
 * @brief Checks win lines in field, adds score in case of win lines
 * @param prms params_t structure
 * @returns quantity of win lines
 */
int check_win_line(params_t *prms) {
  int win_line_count = 0;
  for (int i = 0; i < 20; i++) {
    int win_line = 1;
    for (int j = 0; j < 10; j++) {
      if (!prms->game_info->field[i][j]) win_line = 0;
    }
    if (win_line) {
      move_field_down(prms->game_info, i);
      win_line_count++;
    }
  }
  if (win_line_count == 1) {
    prms->game_info->score += 100;
  } else if (win_line_count == 2) {
    prms->game_info->score += 300;
  } else if (win_line_count == 3) {
    prms->game_info->score += 700;
  } else if (win_line_count >= 4) {
    prms->game_info->score += 1500;
  }
  return win_line_count;
}

/**
 * @brief Removes win line from field and moves field accordingly
 * @param game_info GameInfo_t structure
 * @param x win line row number
 */
void move_field_down(GameInfo_t *game_info, int x) {
  for (int i = x; i > 0; i--) {
    for (int j = 0; j < 10; j++) {
      game_info->field[i][j] = game_info->field[i - 1][j];
    }
  }
}

/**
 * @brief Copies figure from next field to current field
 * @param prms params_t structure
 */
void copy_field(params_t *prms) {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      if (prms->game_info->next[i][j])
        prms->game_info->field[i][j] = prms->game_info->next[i][j];
    }
  }
}

/**
 * @brief Clears next field
 * @param matrix next field
 */
void clear_field(int **matrix) {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      matrix[i][j] = 0;
    }
  }
}

/**
 * @brief Reads maximum score from file
 * @returns maximum score
 */
int read_max_score(void) {
  FILE *file = NULL;
  file = fopen("brick_game/tetris/max_score.txt", "r");
  if (!file) {
    write_max_score(0);
    file = fopen("brick_game/tetris/max_score.txt", "r");
  }
  int max_score = 0;
  if (file) {
    fscanf(file, "%d", &max_score);
    fclose(file);
  } else {
    printf("file brick_game/tetris/max_score.txt does not exist");
    max_score = -1;
  }
  return max_score;
}

/**
 * @brief Writes maximum score to file
 * @returns 0 SUCCESS, 1 FILE ERROR
 */
int write_max_score(int score) {
  FILE *file = NULL;
  int error = 0;
  file = fopen("brick_game/tetris/max_score.txt", "w");
  if (file) {
    fprintf(file, "%d", score);
    fclose(file);
  } else {
    printf("file brick_game/tetris/max_score.txt does not exist");
    error = 1;
  }
  return error;
}