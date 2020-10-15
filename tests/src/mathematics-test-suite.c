
#include <check.h>
#include <libcx.h>
#include <libcx-test-suites.h>

START_TEST(test_abs) {
    ck_assert_int_eq(abs(-1), 1);
    ck_assert_int_eq(abs(0), 0);
    ck_assert_int_eq(abs(1), 1);
}

START_TEST(test_gcd) {
    ck_assert_int_eq(gcd(1,2),1);
    ck_assert_int_eq(gcd(2,4),2);
    ck_assert_int_eq(gcd(15,45),15);
}

START_TEST(test_lcm) {
    ck_assert_int_eq(lcm(1,2),2);
    ck_assert_int_eq(lcm(2,3),6);
    ck_assert_int_eq(lcm(3,6),6);
    ck_assert_int_eq(lcm(3,5),15);
    ck_assert_int_eq(lcm(3,7),21);
}

START_TEST(test_is_prime) {
    ck_assert_int_eq(is_prime(1), true);
    ck_assert_int_eq(is_prime(2), true);
    ck_assert_int_eq(is_prime(3), true);
    ck_assert_int_eq(is_prime(4), false);
    ck_assert_int_eq(is_prime(5), true);
    ck_assert_int_eq(is_prime(62851), true);
    ck_assert_int_eq(is_prime(29393280), false);
    ck_assert_int_eq(is_prime(836145757), true);
}

/**
 * Test suite for the mathematics module.
 *
 */
Suite* mathematics_test_suite(void) {
    TCase* test_case_abs = tcase_create("Absolute Value");
    tcase_add_test(test_case_abs, test_abs);

    TCase* test_case_gcd = tcase_create("Greatest Common Divisor");
    tcase_add_test(test_case_gcd, test_gcd);

    TCase* test_case_lcm = tcase_create("Least Common Multiple");
    tcase_add_test(test_case_lcm, test_lcm);

    TCase* test_case_is_prime = tcase_create("Is Prime");
    tcase_add_test(test_case_is_prime, test_is_prime);

    Suite* test_suite = suite_create("Mathematics Test Suite");
    suite_add_tcase(test_suite, test_case_gcd);
    suite_add_tcase(test_suite, test_case_lcm);
    suite_add_tcase(test_suite, test_case_is_prime);
    suite_add_tcase(test_suite, test_case_abs);

    return test_suite;
}
