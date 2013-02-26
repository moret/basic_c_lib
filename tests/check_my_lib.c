#include <check.h>
#include <stdlib.h>
#include "../src/my_lib.h"

START_TEST (my_test)
{
    fail_unless (my_function() == 42, "Wrong meaning of life, the universe and everything.");
}
END_TEST

Suite *
my_suite(void)
{
    Suite *s = suite_create("my_suite");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, my_test);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s = my_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
