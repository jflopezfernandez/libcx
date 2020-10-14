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

#include "memory.h"

/**
 * This function is meant to replace direct calls to malloc,
 * performing the necessary error-checking on the return
 * value from the memory allocation function, which at the
 * moment is malloc(3).
 *
 */
void* allocate_memory_block(size_t size) {
    /**
     * Call the memory allocation function with the given
     * block size.
     *
     * @note Eventually, it would be nice to be able to
     * specify alternative memory allocation functions, such
     * as jemalloc.
     *
     */
    void* memory_block = malloc(size);

    /**
     * Ensure that the value returned by the memory
     * allocation function points to a valid memory block.
     *
     */
    if (memory_block == NULL) {
        /**
         * Memory allocation functions like malloc(3) use
         * NULL as a sentinel value to indicate an error
         * during memory allocation.
         *
         * One option for more robust error handling would
         * be to print the value of strerror(3) to standard
         * output before exiting.
         *
         * 
         */
        exit(EXIT_FAILURE);
    }

    /**
     * Return the memory block pointer given to use by the
     * memory allocation function.
     *
     */
    return memory_block;
}
