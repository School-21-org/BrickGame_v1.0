#ifndef TETRIS_H
#define TETRIS_H

#include "../../gui/cli/gui.h"
#include "fsm.h"

void game_loop();
bool start();
bool pause_state(GameInfo_t* game_info);
void game_over_loop(GameState_t* g_state, GameInfo_t* game_info);

#endif