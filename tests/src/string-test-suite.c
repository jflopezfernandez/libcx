/*
 * libcx - C Programming Language Extensions Library
 * Copyright (C) 2020 Jose Fernando Lopez Fernandez
 * 
 * This program is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * 
 * You should have received a copy of the GNU General Public
 * License along with this program.  If not, see
 * <https://www.gnu.org/licenses/>.
 *
 */

#include <check.h>
#include <libcx.h>

#include <libcx-test-suites.h>

START_TEST(test_string_length) {
    ck_assert_uint_eq(string_length(""), 0);
    ck_assert_uint_eq(string_length("a"), 1);
    ck_assert_uint_eq(string_length("ab"), 2);
}

START_TEST(test_copy_string) {
    const char* test_string_1 = "abcdefg";
    char* copy = copy_string(test_string_1);
    ck_assert_ptr_nonnull(copy);
    ck_assert_str_eq(test_string_1, copy);
    free(copy);
}

START_TEST(test_concatenate_strings) {
    const char* first = "My name is ";
    const char* second = "Earl.";
    char* greeting = concatenate_strings(first, second);
    ck_assert_ptr_nonnull(greeting);
    ck_assert_str_eq(greeting, "My name is Earl.");
    free(greeting);
}

/**
 * Test suite for the string module.
 *
 */
Suite* string_test_suite(void) {
    TCase* test_case_string_length = tcase_create("String Length");
    tcase_add_test(test_case_string_length, test_string_length);

    TCase* test_case_copy_string = tcase_create("Copy String");
    tcase_add_test(test_case_copy_string, test_copy_string);

    TCase* test_case_concatenate_strings = tcase_create("Concatenate Strings");
    tcase_add_test(test_case_concatenate_strings, test_concatenate_strings);

    Suite* string_module_test_suite = suite_create("String Module Test Suite");
    suite_add_tcase(string_module_test_suite, test_case_string_length);
    suite_add_tcase(string_module_test_suite, test_case_copy_string);
    suite_add_tcase(string_module_test_suite, test_case_concatenate_strings);
    
    return string_module_test_suite;
}
