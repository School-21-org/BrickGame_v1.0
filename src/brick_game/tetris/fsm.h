#ifndef fsm_H
#define fsm_H

#include "backend.h"

void updateCurrentState(UserAction_t user_action, GameInfo_t *game_info,
                        GameState_t *g_state, Figure_t *figure);
UserAction_t get_signal(int user_input);

void spawn(params_t *prms);
void movedown(params_t *prms);
void moveright(params_t *prms);
void moveleft(params_t *prms);
void rotaite(params_t *prms);
void gameover(params_t *prms);
void terminate(params_t *prms);
void pause_game(params_t *prms);

void set_state(params_t *prms, int busy);
void check_max_score(params_t *prms);

#endif