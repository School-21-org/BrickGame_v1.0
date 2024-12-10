#include "test.h"

START_TEST(test_1) {
  GameInfo_t game_info;
  game_info_init(&game_info);

  ck_assert_msg(game_info.score == 0, "game info init failed");
  ck_assert_msg(game_info.high_score == read_max_score(),
                "game info init failed");
  ck_assert_msg(game_info.level == 1, "game info init failed");
  ck_assert_msg(game_info.pause == 0, "game info init failed");
  ck_assert_msg(game_info.speed == SPEED, "game info init failed");

  mem_free(&game_info);
}
END_TEST

START_TEST(test_2) {
  figures figure;
  figure = select_figure(0);

  ck_assert_msg((int)figure >= 0 && (int)figure <= 6, "select_figure failed");
}
END_TEST

START_TEST(test_3) {
  figures figure = 2;
  figure = select_figure(figure);

  ck_assert_msg((int)figure >= 0 && (int)figure <= 6 && (int)figure != 2,
                "select_figure failed");
}
END_TEST

START_TEST(test_4) {
  UserAction_t user_action = Start;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = START;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 0, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 3, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  for (int i = 0; i < P_FIELD_HEIGHT; i++) {
    for (int j = 0; j < P_FIELD_WIDTH; j++) {
      if (j == figure.x1 && i == figure.y1)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x2 && i == figure.y2)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x3 && i == figure.y3)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x4 && i == figure.y4)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
    }
  }

  mem_free(&game_info);
}
END_TEST

START_TEST(test_5) {
  UserAction_t user_action = Left;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = START;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 0, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 3, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  for (int i = 0; i < P_FIELD_HEIGHT; i++) {
    for (int j = 0; j < P_FIELD_WIDTH; j++) {
      if (j == figure.x1 && i == figure.y1)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x2 && i == figure.y2)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x3 && i == figure.y3)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x4 && i == figure.y4)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
    }
  }

  mem_free(&game_info);
}
END_TEST

START_TEST(test_6) {
  UserAction_t user_action = Right;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = START;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 0, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 3, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  for (int i = 0; i < P_FIELD_HEIGHT; i++) {
    for (int j = 0; j < P_FIELD_WIDTH; j++) {
      if (j == figure.x1 && i == figure.y1)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x2 && i == figure.y2)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x3 && i == figure.y3)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x4 && i == figure.y4)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
    }
  }

  mem_free(&game_info);
}
END_TEST

START_TEST(test_7) {
  UserAction_t user_action = Up;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = START;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 0, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 3, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  for (int i = 0; i < P_FIELD_HEIGHT; i++) {
    for (int j = 0; j < P_FIELD_WIDTH; j++) {
      if (j == figure.x1 && i == figure.y1)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x2 && i == figure.y2)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x3 && i == figure.y3)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x4 && i == figure.y4)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
    }
  }

  mem_free(&game_info);
}
END_TEST

START_TEST(test_8) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = START;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 0, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 3, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  for (int i = 0; i < P_FIELD_HEIGHT; i++) {
    for (int j = 0; j < P_FIELD_WIDTH; j++) {
      if (j == figure.x1 && i == figure.y1)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x2 && i == figure.y2)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x3 && i == figure.y3)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x4 && i == figure.y4)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
    }
  }

  mem_free(&game_info);
}
END_TEST

START_TEST(test_9) {
  UserAction_t user_action = Action;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = START;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 0, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 3, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  for (int i = 0; i < P_FIELD_HEIGHT; i++) {
    for (int j = 0; j < P_FIELD_WIDTH; j++) {
      if (j == figure.x1 && i == figure.y1)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x2 && i == figure.y2)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x3 && i == figure.y3)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
      if (j == figure.x4 && i == figure.y4)
        ck_assert_msg(game_info.field[i][j] == 1, "field fill failed");
    }
  }

  mem_free(&game_info);
}
END_TEST

START_TEST(test_10) {
  UserAction_t user_action = Pause;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = START;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(game_info.pause == 1, "game_info.pause failed");

  mem_free(&game_info);
}
END_TEST

START_TEST(test_11) {
  UserAction_t user_action = Terminate;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = START;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(g_state == EXIT_STATE, "g_state failed");

  mem_free(&game_info);
}
END_TEST

START_TEST(test_12) {
  UserAction_t user_action = Pause;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = SPAWN;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(game_info.pause == 1, "game_info.pause failed");

  mem_free(&game_info);
}
END_TEST

START_TEST(test_13) {
  UserAction_t user_action = Terminate;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = SPAWN;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(g_state == EXIT_STATE, "g_state failed");

  mem_free(&game_info);
}
END_TEST

START_TEST(test_14) {
  UserAction_t user_action = Start;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = SPAWN;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(g_state == SPAWN, "g_state failed");

  mem_free(&game_info);
}
END_TEST

START_TEST(test_15) {
  UserAction_t user_action = Left;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = SPAWN;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(g_state == SPAWN, "g_state failed");

  mem_free(&game_info);
}
END_TEST

START_TEST(test_16) {
  UserAction_t user_action = Right;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = SPAWN;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(g_state == SPAWN, "g_state failed");

  mem_free(&game_info);
}
END_TEST

START_TEST(test_17) {
  UserAction_t user_action = Up;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = SPAWN;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(g_state == SPAWN, "g_state failed");

  mem_free(&game_info);
}
END_TEST

START_TEST(test_18) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = SPAWN;
  Figure_t figure;
  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(g_state == SPAWN, "g_state failed");

  mem_free(&game_info);
}
END_TEST

// simple move down I_BLOCK state_1
START_TEST(test_19) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 3;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 3, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down I_BLOCK state_2
START_TEST(test_20) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 2;
  figure.x2 = figure.x_pos + 2;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 2;
  figure.y4 = figure.y_pos + 3;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_2, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 3, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down I_BLOCK state_3
START_TEST(test_21) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 3;
  figure.y1 = figure.y_pos + 2;
  figure.y2 = figure.y_pos + 2;
  figure.y3 = figure.y_pos + 2;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_3, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 3, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down I_BLOCK state_4
START_TEST(test_22) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 1;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 2;
  figure.y4 = figure.y_pos + 3;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_4, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 1, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 3, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down J_BLOCK state_1
START_TEST(test_23) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = J_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == J_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down J_BLOCK state_2
START_TEST(test_24) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = J_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 2;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 1;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == J_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_2, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 1, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down J_BLOCK state_3
START_TEST(test_25) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = J_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == J_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_3, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down J_BLOCK state_4
START_TEST(test_26) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = J_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 2;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == J_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_4, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down L_BLOCK state_1
START_TEST(test_27) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = L_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 2;
  figure.x2 = figure.x_pos;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == L_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down L_BLOCK state_2
START_TEST(test_28) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = L_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 2;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == L_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_2, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down L_BLOCK state_3
START_TEST(test_29) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = L_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos + 2;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == L_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_3, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down L_BLOCK state_4
START_TEST(test_30) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = L_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 1;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == L_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_4, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 1, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down O_BLOCK state_1
START_TEST(test_31) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = O_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 2;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == O_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down O_BLOCK state_2
START_TEST(test_32) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = O_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 2;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == O_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_2, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down O_BLOCK state_3
START_TEST(test_33) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = O_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 2;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == O_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_3, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down O_BLOCK state_4
START_TEST(test_34) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = O_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 2;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == O_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_4, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down S_BLOCK state_1
START_TEST(test_35) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = S_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 2;
  figure.x3 = figure.x_pos;
  figure.x4 = figure.x_pos + 1;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == S_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 1, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down S_BLOCK state_2
START_TEST(test_36) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = S_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == S_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_2, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down S_BLOCK state_3
START_TEST(test_37) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = S_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 0;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos + 2;
  figure.y2 = figure.y_pos + 2;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == S_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_3, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down S_BLOCK state_4
START_TEST(test_38) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = S_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 0;
  figure.x2 = figure.x_pos + 0;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 1;
  figure.y1 = figure.y_pos + 0;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == S_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_4, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 1, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down T_BLOCK state_1
START_TEST(test_39) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = T_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 0;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos + 0;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == T_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down T_BLOCK state_2
START_TEST(test_40) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = T_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos + 0;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 2;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == T_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_2, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 1, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down T_BLOCK state_3
START_TEST(test_41) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = T_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 0;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 1;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == T_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_3, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 1, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down T_BLOCK state_4
START_TEST(test_42) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = T_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 0;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 1;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 0;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == T_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_4, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 1, "figure coordinates failed");

  ck_assert_msg(figure.y1 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down Z_BLOCK state_1
START_TEST(test_43) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = Z_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 2;
  figure.x3 = figure.x_pos + 0;
  figure.x4 = figure.x_pos + 1;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 0;
  figure.y4 = figure.y_pos + 0;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == Z_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y1 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 0, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down Z_BLOCK state_2
START_TEST(test_44) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = Z_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 2;
  figure.x2 = figure.x_pos + 2;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 1;
  figure.y1 = figure.y_pos + 0;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == Z_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_2, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y1 == figure.y_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down Z_BLOCK state_3
START_TEST(test_45) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = Z_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 0;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 1;
  figure.x4 = figure.x_pos + 2;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 2;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == Z_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_3, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y1 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 2, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// simple move down Z_BLOCK state_4
START_TEST(test_46) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = Z_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos + 1;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 0;
  figure.x4 = figure.x_pos + 0;
  figure.y1 = figure.y_pos + 0;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 2;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == Z_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_4, "figure.state failed");
  ck_assert_msg(g_state == MOVING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  ck_assert_msg(figure.x1 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x2 == figure.x_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.x3 == figure.x_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.x4 == figure.x_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.y1 == figure.y_pos + 0, "figure coordinates failed");
  ck_assert_msg(figure.y2 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y3 == figure.y_pos + 1, "figure coordinates failed");
  ck_assert_msg(figure.y4 == figure.y_pos + 2, "figure coordinates failed");

  ck_assert_msg(game_info.field[figure.y1][figure.x1] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y2][figure.x2] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y3][figure.x3] == 1,
                "field fill failed");
  ck_assert_msg(game_info.field[figure.y4][figure.x4] == 1,
                "field fill failed");

  mem_free(&game_info);
}
END_TEST

// win case 1
START_TEST(test_47) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 18;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 3;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  game_info.field[19][0] = 1;
  game_info.field[19][1] = 1;
  game_info.field[19][2] = 1;
  game_info.field[19][7] = 1;
  game_info.field[19][8] = 1;
  game_info.field[19][9] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 19, "figure.y_pos failed");

  ck_assert_msg(game_info.score == 100, "score failed");
  ck_assert_msg(game_info.speed == 600, "speed failed");
  ck_assert_msg(game_info.level == 1, "speed failed");

  mem_free(&game_info);
}
END_TEST

// win case 2
START_TEST(test_48) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 18;
  game_info.score = 500;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 3;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  game_info.field[19][0] = 1;
  game_info.field[19][1] = 1;
  game_info.field[19][2] = 1;
  game_info.field[19][7] = 1;
  game_info.field[19][8] = 1;
  game_info.field[19][9] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 19, "figure.y_pos failed");

  ck_assert_msg(game_info.score == 600, "score failed");
  ck_assert_msg(game_info.speed == 550, "speed failed");
  ck_assert_msg(game_info.level == 2, "speed failed");

  mem_free(&game_info);
}
END_TEST

// win case 3
START_TEST(test_49) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 17;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 3;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  game_info.field[18][0] = 1;
  game_info.field[18][1] = 1;
  game_info.field[18][2] = 1;
  game_info.field[18][7] = 1;
  game_info.field[18][8] = 1;
  game_info.field[18][9] = 1;

  for (int j = 0; j < 10; j++) game_info.field[19][j] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

  ck_assert_msg(game_info.score == 300, "score failed");
  ck_assert_msg(game_info.speed == 600, "speed failed");
  ck_assert_msg(game_info.level == 1, "speed failed");

  mem_free(&game_info);
}
END_TEST

// win case 4
START_TEST(test_50) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 16;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 3;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  game_info.field[17][0] = 1;
  game_info.field[17][1] = 1;
  game_info.field[17][2] = 1;
  game_info.field[17][7] = 1;
  game_info.field[17][8] = 1;
  game_info.field[17][9] = 1;

  for (int j = 0; j < 10; j++) {
    game_info.field[19][j] = 1;
    game_info.field[18][j] = 1;
  }

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 17, "figure.y_pos failed");

  ck_assert_msg(game_info.score == 700, "score failed");
  ck_assert_msg(game_info.speed == 550, "speed failed");
  ck_assert_msg(game_info.level == 2, "speed failed");

  mem_free(&game_info);
}
END_TEST

// win case 5
START_TEST(test_51) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 15;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 3;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  game_info.field[16][0] = 1;
  game_info.field[16][1] = 1;
  game_info.field[16][2] = 1;
  game_info.field[16][7] = 1;
  game_info.field[16][8] = 1;
  game_info.field[16][9] = 1;

  for (int j = 0; j < 10; j++) {
    game_info.field[19][j] = 1;
    game_info.field[18][j] = 1;
    game_info.field[17][j] = 1;
  }

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 16, "figure.y_pos failed");

  ck_assert_msg(game_info.score == 1500, "score failed");
  ck_assert_msg(game_info.speed == 500, "speed failed");
  ck_assert_msg(game_info.level == 3, "speed failed");

  mem_free(&game_info);
}
END_TEST

// get signal
START_TEST(test_52) {
  ck_assert_msg(get_signal(0402) == Down, "Down signal failed");
  ck_assert_msg(get_signal(0404) == Left, "Left signal failed");
  ck_assert_msg(get_signal(0405) == Right, "Right signal failed");
  ck_assert_msg(get_signal(27) == Terminate, "Terminate signal failed");
  ck_assert_msg(get_signal(10) == Pause, "Pause signal failed");
  ck_assert_msg(get_signal(32) == Action, "Action signal failed");
  ck_assert_msg(get_signal(55) == Start, "Start signal failed");
}
END_TEST

// exit
START_TEST(test_53) {
  UserAction_t user_action = Terminate;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 1;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 3;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == EXIT_STATE, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 1, "figure.y_pos failed");

  mem_free(&game_info);
}
END_TEST

// game over
START_TEST(test_54) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = START;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 0;

  figure.x1 = figure.x_pos;
  figure.x2 = figure.x_pos + 1;
  figure.x3 = figure.x_pos + 2;
  figure.x4 = figure.x_pos + 3;
  figure.y1 = figure.y_pos + 1;
  figure.y2 = figure.y_pos + 1;
  figure.y3 = figure.y_pos + 1;
  figure.y4 = figure.y_pos + 1;

  game_info.field[figure.y1][figure.x1] = 1;
  game_info.field[figure.y2][figure.x2] = 1;
  game_info.field[figure.y3][figure.x3] = 1;
  game_info.field[figure.y4][figure.x4] = 1;

  game_info.field[1][4] = 1;

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == GAMEOVER, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 0, "figure.y_pos failed");

  mem_free(&game_info);
}
END_TEST

Suite *test_fsm(void) {
  Suite *suite = suite_create("test_fsm");
  TCase *tcase_core = tcase_create("test_fsm");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  tcase_add_test(tcase_core, test_6);
  tcase_add_test(tcase_core, test_7);
  tcase_add_test(tcase_core, test_8);
  tcase_add_test(tcase_core, test_9);
  tcase_add_test(tcase_core, test_10);
  tcase_add_test(tcase_core, test_11);
  tcase_add_test(tcase_core, test_12);
  tcase_add_test(tcase_core, test_13);
  tcase_add_test(tcase_core, test_14);
  tcase_add_test(tcase_core, test_15);
  tcase_add_test(tcase_core, test_16);
  tcase_add_test(tcase_core, test_17);
  tcase_add_test(tcase_core, test_18);
  tcase_add_test(tcase_core, test_19);
  tcase_add_test(tcase_core, test_20);
  tcase_add_test(tcase_core, test_21);
  tcase_add_test(tcase_core, test_22);
  tcase_add_test(tcase_core, test_23);
  tcase_add_test(tcase_core, test_24);
  tcase_add_test(tcase_core, test_25);
  tcase_add_test(tcase_core, test_26);
  tcase_add_test(tcase_core, test_27);
  tcase_add_test(tcase_core, test_28);
  tcase_add_test(tcase_core, test_29);
  tcase_add_test(tcase_core, test_30);
  tcase_add_test(tcase_core, test_31);
  tcase_add_test(tcase_core, test_32);
  tcase_add_test(tcase_core, test_33);
  tcase_add_test(tcase_core, test_34);
  tcase_add_test(tcase_core, test_35);
  tcase_add_test(tcase_core, test_36);
  tcase_add_test(tcase_core, test_37);
  tcase_add_test(tcase_core, test_38);
  tcase_add_test(tcase_core, test_39);
  tcase_add_test(tcase_core, test_40);
  tcase_add_test(tcase_core, test_41);
  tcase_add_test(tcase_core, test_42);
  tcase_add_test(tcase_core, test_43);
  tcase_add_test(tcase_core, test_44);
  tcase_add_test(tcase_core, test_45);
  tcase_add_test(tcase_core, test_46);
  tcase_add_test(tcase_core, test_47);
  tcase_add_test(tcase_core, test_48);
  tcase_add_test(tcase_core, test_49);
  tcase_add_test(tcase_core, test_50);
  tcase_add_test(tcase_core, test_51);
  tcase_add_test(tcase_core, test_52);
  tcase_add_test(tcase_core, test_53);
  tcase_add_test(tcase_core, test_54);

  suite_add_tcase(suite, tcase_core);
  return suite;
}