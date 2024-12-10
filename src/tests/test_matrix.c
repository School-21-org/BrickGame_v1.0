#include "test.h"

START_TEST(test_1) {
  GameInfo_t game_info;
  field_memory_allocation(&game_info);

  for (int i = 0; i < P_FIELD_HEIGHT; i++) {
    for (int j = 0; j < P_FIELD_WIDTH; j++) {
      ck_assert_msg(game_info.field[i][j] == 0, "field mem allocation failed");
      ck_assert_msg(game_info.next[i][j] == 0, "next mem allocation failed");
    }
  }

  mem_free(&game_info);
}
END_TEST

Suite *test_matrix(void) {
  Suite *suite = suite_create("test_matrix");
  TCase *tcase_core = tcase_create("test_matrix");

  tcase_add_test(tcase_core, test_1);

  suite_add_tcase(suite, tcase_core);
  return suite;
}