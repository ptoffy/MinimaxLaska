/**
 * @file Bool.h
 * @author Paul Toffoloni
 * @date August 19, 2021
 * @brief Boolean enum.
 *
 * Bool represents a boolean value enum.
 *
 */

#ifndef LASCA_BOOL_H
#define LASCA_BOOL_H

/**
 * @brief Boolean value enum.
 * A data type representing the concepts of true or false,
 * not available in C90.
 * Most programming languages recognize any non-zero value as being true.
 */
typedef enum bool {
    false = 0,
    true = 1
} bool;

/**
 * Returns a string containing the boolean value, in italian.
 * @param b The boolean value to return the string from.
 * @return The string created from the boolean value.
 */
const char*
get_bool_string(bool b);

#endif /* LASCA_BOOL_H */
