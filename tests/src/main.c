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

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <check.h>

#include <libcx.h>
#include <libcx-test-suites.h>

int main(void)
{
    Suite* main_test_suite = suite_create("libcx Tests");
    SRunner* test_runner = srunner_create(main_test_suite);

    srunner_add_suite(test_runner, mathematics_test_suite());
    srunner_add_suite(test_runner, memory_test_suite());
    srunner_add_suite(test_runner, string_test_suite());

    srunner_run_all(test_runner, CK_VERBOSE);

    int tests_failed = srunner_ntests_failed(test_runner);

    srunner_free(test_runner);

    return tests_failed;
}
