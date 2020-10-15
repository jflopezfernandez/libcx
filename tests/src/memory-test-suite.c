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
#include <stdlib.h>
#include <check.h>
#include <libcx.h>

START_TEST(test_allocation_function_returns_nonnull) {
    char* test_block = allocate_memory_block(1024);
    ck_assert_ptr_nonnull(test_block);
    free(test_block);
}

/**
 * Test suite for the memory extension module.
 *
 */
Suite* memory_test_suite(void) {
    TCase* test_case_allocation_function_returns_nonnull = tcase_create("Allocation returns non-null");
    tcase_add_test(test_case_allocation_function_returns_nonnull, test_allocation_function_returns_nonnull);

    Suite* memory_module_test_suite = suite_create("Memory Module Test Suite");
    suite_add_tcase(memory_module_test_suite, test_case_allocation_function_returns_nonnull);

    return memory_module_test_suite;
}
