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

#ifndef PROJECT_INCLUDES_STRING_H
#define PROJECT_INCLUDES_STRING_H

/**
 * This macro definition is required for Doxygen to be able
 * to parse the function declaration correctly.
 *
 * @def __attributes_string_length
 *
 */
#ifndef __attributes_string_length
#define __attributes_string_length __attribute__((nonnull(1), pure))
#endif

/*
 * Calculate the length of the given string.
 *
 * The function returns the length of the string pointed to
 * by <U>string</U>, excluding the null terminator.
 *
 * @param[in] string Pointer to null-terminated string.
 *
 * @returns Length of the given string, minus null terminator.
 *
 */
size_t
__attributes_string_length
string_length(const char* string);

/**
 * This macro definition is required for Doxygen to be able
 * to parse the function declaration correctly.
 *
 * @def __attributes_copy_string
 *
 */
#ifndef __attributes_copy_string
#define __attributes_copy_string __attribute__((nonnull(1), returns_nonnull))
#endif

/*
 * Copy a string.
 *
 * This function performs a deep copy of the string pointed
 * to by <U>original</U>, taking care of heap-allocating the
 * necessary memory for the new string.
 *
 * @param[in] original String to copy.
 *
 * @returns Heap-allocated copy of the original string.
 *
 * @todo Write man page for this function.
 *
 */
char*
__attributes_copy_string
copy_string(const char* original);

/**
 * This macro definition is required for Doxygen to be able
 * to parse the function declaration correctly.
 *
 * @def __attributes_copy_string
 *
 */
#ifndef __attributes_concatenate_strings
#define __attributes_concatenate_strings __attribute__((nonnull(1,2), returns_nonnull))
#endif

/*
 * Concatenate two strings.
 *
 * This function performs the concatenation of the two
 * strings given by <U>first</U> and <U>second</U> by first
 * heap-allocating enough memory for the result string to
 * hold the entire first string (excluding the null terminator)
 * and the entire second string (including the null terminator).
 * In other words, the length of the returned string is equal
 * to: strlen(first) + strlen(second) + 1.
 *
 * @param[in] first The first string.
 * @param[in] second The string to append to the first string.
 *
 * @returns A heap-allocated string containing both original
 * strings, minus the null terminator of the first string.
 *
 * @todo Write man page for this function.
 *
 */
char*
__attributes_concatenate_strings
concatenate_strings(const char* first, const char* second);

#endif /** PROJECT_INCLUDES_STRING_H */
