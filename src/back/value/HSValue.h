/*
HabaScript value object definition
* May be used in front (C++)
*/

#pragma once

#include "../../HSGlobals.h"
#include "HSRaws.h"

typedef enum {
    HS_TYPE_NULL, HS_TYPE_BOOL, HS_TYPE_INT, HS_TYPE_FLOAT
} HSType;

typedef enum {
    HS_VS_FREE, HS_VS_CONSTANT, HS_VS_DYNAMIC, HS_VS_GC_MARKER = 0x80000000
} HSValueState;

typedef struct {
    HSRaw raw;
    union {
        HS_CSizeT i_type;
        HSType type;
    };
    union {
        HS_CSizeT i_value_state;
        HSValueState value_state;
    };
} HSValue;

extern HSValue hs_hsvalue_constant_null;

#ifdef __cplusplus
extern "C" {
#endif
HSValue* hs_hsvalue_getnull();
#ifdef __cplusplus
}
#endif