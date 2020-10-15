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
#include <libcx.h>

/**
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
size_t string_length(const char* string) {
    size_t length = 0;

    while (string[length] != '\0') {
        ++length;
    }
    
    return length;
}

/**
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
 */
char* copy_string(const char* original) {
    /** Get the length of the original string. */
    size_t length = string_length(original);

    /** Allocate the necessary memory to hold the copy. */
    char* copy = allocate_memory_block(sizeof (char) * (length + 1));

    /** Copy the contents of the original string into the copy. */
    for (size_t i = 0; i < length + 1; ++i) {
        copy[i] = original[i];
    }

    return copy;
}

/**
 * Concatenate two strings.
 *
 * This function performs the concatenation of the two
 * strings given by <U>first</U> and <U>second</U> by first
 * heap-allocating enough memory for the result string to
 * hold the entire first string (excluding the null terminator)
 * and the entire second string (including the null terminator).
 * In other words, the length of the returned string is equal
 * to the following equation.
 * \f[ \text{strlen}\left(\text{combined string}\right) = \text{strlen}\left(\text{first}\right) + \text{strlen}\left(\text{second}\right) + 1 \f]
 *
 * @param[in] first The first string.
 * @param[in] second The string to append to the first string.
 *
 * @returns A heap-allocated string containing both original
 * strings, minus the null terminator of the first string.
 *
 */
char* concatenate_strings(const char* first, const char* second) {
    size_t length_first = string_length(first);
    size_t length_second = string_length(second);
    char* combined_string = allocate_memory_block(sizeof (char) * (length_first + length_second + 1));

    size_t index = 0;

    for (size_t i = 0; i < length_first; ++i) {
        combined_string[index++] = first[i];
    }

    for (size_t i = 0; i <= length_second; ++i) {
        combined_string[index++] = second[i];
    }

    return combined_string;
}
