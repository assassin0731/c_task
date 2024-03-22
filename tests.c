#include <check.h>
#include "quadratic_equation.h"


START_TEST(test_1) {
    char* result = solve_equation(1, 2, 1);
    ck_assert_pstr_eq(result, "-1.000000");
}
END_TEST

START_TEST(test_2) {
    char* result = solve_equation(1, 2, 3);
    ck_assert_pstr_eq(result, "No solution");
}
END_TEST

START_TEST(test_3) {
    char* result = solve_equation(2, -3, 4);
    ck_assert_pstr_eq(result, "No solution");
}
END_TEST

START_TEST(test_4) {
    char* result = solve_equation(1, 3, 1);
    ck_assert_pstr_eq(result, "-2.618034 -0.381966");
}
END_TEST

START_TEST(test_5) {
    char* result = solve_equation(2, -6, 4);
    ck_assert_pstr_eq(result, "1.000000 2.000000");
}
END_TEST

START_TEST(test_6) {
    char* result = solve_equation(1, -6, 9);
    ck_assert_pstr_eq(result, "3.000000");
}
END_TEST

int main() {
  Suite *s1 = suite_create("Tests: ");
  TCase *tc1_1 = tcase_create("Tests: ");
  SRunner *sr = srunner_create(s1);
  int result;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, test_1);
  tcase_add_test(tc1_1, test_2);
  tcase_add_test(tc1_1, test_3);
  tcase_add_test(tc1_1, test_4);
  tcase_add_test(tc1_1, test_5);
  tcase_add_test(tc1_1, test_6);

  srunner_run_all(sr, CK_ENV);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result == 0 ? 0 : 1;
}
