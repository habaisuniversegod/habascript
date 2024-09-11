/*
HabaScript raw value definition (structure that contains C-values)
*/

#pragma once

#include "../../HSGlobals.h"
#include <stdint.h>

typedef int_fast64_t HS_CInteger;
typedef int HS_CBoolean;
typedef double HS_CFloat;

typedef union {
    HS_CInteger as_int;
    HS_CBoolean as_bool;
    HS_CFloat as_float;
    uint8_t alignment[24];
} HSRaw;
