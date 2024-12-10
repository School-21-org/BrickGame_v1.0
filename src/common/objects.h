#ifndef OBJECTS_H
#define OBJECTS_H

typedef enum {
  START = 0,
  SPAWN,
  MOVING,
  SHIFTING,
  ATTACHING,
  GAMEOVER,
  EXIT_STATE
} GameState_t;

typedef enum {
  I_BLOCK = 0,
  J_BLOCK,
  L_BLOCK,
  O_BLOCK,
  S_BLOCK,
  T_BLOCK,
  Z_BLOCK
} figures;

typedef enum { state_1 = 0, state_2, state_3, state_4 } f_state;

typedef struct figures {
  figures type, type_next;
  f_state state;
  int y_pos;
  int x_pos;
  int x1, x2, x3, x4, y1, y2, y3, y4;
} Figure_t;

typedef enum {
  Start = 0,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

#endif