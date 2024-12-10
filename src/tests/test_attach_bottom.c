#include "test.h"

// attaching to bottom I_BLOCK state_1
START_TEST(test_1) {
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

  updateCurrentState(user_action, &game_info, &g_state, &figure);

  ck_assert_msg(figure.type == I_BLOCK, "figure.type failed");
  ck_assert_msg(figure.state == state_1, "figure.state failed");
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 19, "figure.y_pos failed");

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

// attaching to bottom I_BLOCK state_2
START_TEST(test_2) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 16;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 17, "figure.y_pos failed");

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

// attaching to bottom I_BLOCK state_3
START_TEST(test_3) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom I_BLOCK state_4
START_TEST(test_4) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = I_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 16;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 17, "figure.y_pos failed");

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

// attaching to bottom J_BLOCK state_1
START_TEST(test_5) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = J_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 18;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 19, "figure.y_pos failed");

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

// attaching to bottom J_BLOCK state_2
START_TEST(test_6) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = J_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom J_BLOCK state_3
START_TEST(test_7) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = J_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom J_BLOCK state_4
START_TEST(test_8) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = J_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom L_BLOCK state_1
START_TEST(test_9) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = L_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 18;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 19, "figure.y_pos failed");

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

// attaching to bottom L_BLOCK state_2
START_TEST(test_10) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = L_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom L_BLOCK state_3
START_TEST(test_11) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = L_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom L_BLOCK state_4
START_TEST(test_12) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = L_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom O_BLOCK state_1
START_TEST(test_13) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = O_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 18;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 19, "figure.y_pos failed");

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

// attaching to bottom O_BLOCK state_2
START_TEST(test_14) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = O_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 18;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 19, "figure.y_pos failed");

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

// attaching to bottom O_BLOCK state_3
START_TEST(test_15) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = O_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 18;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 19, "figure.y_pos failed");

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

// attaching to bottom O_BLOCK state_4
START_TEST(test_16) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = O_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 18;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 19, "figure.y_pos failed");

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

// attaching to bottom S_BLOCK state_1
START_TEST(test_17) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = S_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 18;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 19, "figure.y_pos failed");

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

// attaching to bottom S_BLOCK state_2
START_TEST(test_18) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = S_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom S_BLOCK state_3
START_TEST(test_19) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = S_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom S_BLOCK state_4
START_TEST(test_20) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = S_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom T_BLOCK state_1
START_TEST(test_21) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = T_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 18;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 19, "figure.y_pos failed");

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

// attaching to bottom T_BLOCK state_2
START_TEST(test_22) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = T_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom T_BLOCK state_3
START_TEST(test_23) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = T_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom T_BLOCK state_4
START_TEST(test_24) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = T_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom Z_BLOCK state_1
START_TEST(test_25) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = Z_BLOCK;
  figure.state = state_1;
  figure.x_pos = 3;
  figure.y_pos = 18;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 19, "figure.y_pos failed");

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

// attaching to bottom Z_BLOCK state_2
START_TEST(test_26) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = Z_BLOCK;
  figure.state = state_2;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom Z_BLOCK state_3
START_TEST(test_27) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = Z_BLOCK;
  figure.state = state_3;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

// attaching to bottom Z_BLOCK state_4
START_TEST(test_28) {
  UserAction_t user_action = Down;
  GameInfo_t game_info;
  game_info_init(&game_info);
  GameState_t g_state = MOVING;
  Figure_t figure;

  figure.type = Z_BLOCK;
  figure.state = state_4;
  figure.x_pos = 3;
  figure.y_pos = 17;

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
  ck_assert_msg(g_state == ATTACHING, "g_state failed");
  ck_assert_msg(figure.x_pos == 3, "figure.x_pos failed");
  ck_assert_msg(figure.y_pos == 18, "figure.y_pos failed");

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

Suite *test_attaching(void) {
  Suite *suite = suite_create("test_attaching");
  TCase *tcase_core = tcase_create("test_attaching");

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

  suite_add_tcase(suite, tcase_core);
  return suite;
}