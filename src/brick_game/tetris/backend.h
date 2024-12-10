#ifndef backend_H
#define backend_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include "../../common/defines.h"
#include "../../common/objects.h"

typedef struct game_params {
  GameInfo_t *game_info;
  Figure_t *figure;
  GameState_t *g_state;
  UserAction_t *user_action;
} params_t;

typedef struct coordinates {
  int x1, x2, x3, x4, y1, y2, y3, y4;
} coordinates_t;

void clear_field(int **matrix);
void copy_field(params_t *prms);

figures select_figure(figures figure);

int fill_figure(params_t *prms);
int fill_i_block(params_t *prms);
int fill_j_block(params_t *prms);
int fill_l_block(params_t *prms);
int fill_o_block(params_t *prms);
int fill_s_block(params_t *prms);
int fill_t_block(params_t *prms);
int fill_z_block(params_t *prms);
int check_figure(params_t *prms, const coordinates_t *crdnts);
void fill_coordinates(params_t *prms, const coordinates_t *cdnts);
void temporary_fill_block(params_t *prms, int value);
int check_figures_overlay(params_t *prms, const coordinates_t *crdnts);

int check_win_line(params_t *prms);
void move_field_down(GameInfo_t *game_info, int x);
int read_max_score(void);
int write_max_score(int score);

void up_level(GameInfo_t *game_info);

void game_info_init(GameInfo_t *game_info);
int field_memory_allocation(GameInfo_t *game_info);
void mem_free(GameInfo_t *game_info);
long long current_timestamp();

#endif