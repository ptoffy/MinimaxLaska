//
// Created by Paul Toffoloni on 19/08/21.
//

#ifndef LASCA_BOOL_H
#define LASCA_BOOL_H

/**
 * Enum representing boolean value, not available in C90.
 */
typedef enum bool {
    false = 0,
    true = 1
} bool;

/**
 * Returns a string containing the boolena value, in italian.
 * @param b The boolean value to return the string from.
 * @return The string created from the boolean value.
 */
const char* get_bool_string(bool b);

#endif //LASCA_BOOL_H
