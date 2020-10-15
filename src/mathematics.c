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
#include <stdint.h>
#include <libcx.h>

/**
 * Absolute Value
 *
 * This function returns the absolute value of the input,
 * except for the case where the input is zero, in which
 * case the result is again zero.
 *
 * @param[in] x The number to evalue the absolute value of.
 *
 * @returns The absolute value of the integer x.
 *
 */
int abs(int x) {
    return ((x < 0) ? -(x) : (x));
}

/**
 * Greatest Common Divisor
 *
 * This function computes the greatest common divisor of two
 * integers using a simple implementation of the Euclidean
 * algorithm that does not rely on division operations. I
 * have not performed a comparative profile of this method
 * versus one using division operations, but my hunch is
 * that this method is faster. As I said, however, this
 * hunch is based on zero actual information.
 *
 * @param[in] a First factor.
 * @param[in] b Second factor.
 *
 * @returns The greatest common divisor of a and b.
 *
 * @note In order for this simpler subtraction-based
 * algorithm to work, both numbers must be greater than zero
 * (obviously), as otherwise the algorithm would never
 * terminate.
 *
 */
int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }

    return a;
}

/**
 * Least Common Multiple
 *
 * This function returns the least common multiple of the
 * integers a and b by leveraging the Greatest Common
 * Denominator function defined within this same module.
 *
 * @param[in] a First factor.
 * @param[in] b Second factor.
 *
 * @returns The smallest integer divisible by both a and b.
 *
 * @remark The requirement that both a and b be non-negative
 * integers applies in this function just as it does in the
 * gcd() function, since it is implicitly used in the final
 * calculation.
 *
 */
int lcm(int a, int b) {
    return (a * b) / gcd(a,b);
}

/**
 * Is Prime
 *
 * This function checks whether a given number is prime by
 * brute-force, attempting to divide the given number \f$n\f$ by
 * every number \f$n-1\f$.
 *
 * @param[in] n The number to test for primality.
 *
 * @returns A boolean value which is true if \f$n\f$ is prime.
 *
 * @note As is customary in mathematics, \f$1\f$ is
 * considered prime.
 *
 */
bool_t is_prime(int n) {
    if (n == 1) {
        return true;
    }

    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
