//
// Created by Paul Toffoloni on 20/08/21.
//


#include "Bool.h"

const char* get_bool_string(bool b) {
    switch (b) {
        case true: return "Vero";
        case false: return "Falso";
        default: return "";
    }
}
