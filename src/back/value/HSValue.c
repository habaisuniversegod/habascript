#include "HSValue.h"

HSValue hs_hsvalue_constant_null = {.raw = {.as_int = 0}, .type = HS_TYPE_NULL, .value_state = HS_VS_FREE};

HSValue *hs_hsvalue_getnull()
{
    return &hs_hsvalue_constant_null;
}
