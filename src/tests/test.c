#include "test.h"

int main() {
  Suite *cases[] = {test_matrix(),          test_fsm(),
                    test_attaching(),       test_attaching_figure(),
                    test_move_left(),       test_move_right(),
                    test_move_left_shift(), test_move_right_shift(),
                    test_rotaite(),         NULL};

  int total = 0;
  int failed = 0;

  for (int i = 0; i < (int)(sizeof(cases) / sizeof(cases[0])); i++) {
    printf("\n");
    SRunner *sr = srunner_create(cases[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    total += srunner_ntests_run(sr);
    srunner_free(sr);
  }
  printf("\n");

  printf("Total: %d\nFailed: %d\nPassed: %d\n", total, failed, total - failed);

  return 0;
}