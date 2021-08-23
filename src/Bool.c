/**
 * @file Bool.c
 * @author Paul Toffoloni
 * @date August 19, 2021
 * @brief Boolean enum.
 *
 * Bool represents a boolean value enum.
 *
 */

#include "Bool.h"

const char* get_bool_string(bool b) {
    switch (b) {
        case true: return "Vero";
        case false: return "Falso";
        default: return "";
    }
}
