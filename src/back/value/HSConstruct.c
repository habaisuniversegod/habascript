#include "HSConstruct.h"

void hs_hsvalue_construct_null(HSValue *vs, HSValueState state)
{
    vs->raw.as_int = (HS_CInteger)0;
    vs->type = HS_TYPE_NULL;
    vs->value_state = state;
}

void hs_hsvalue_construct_bool(HSValue *vs, HS_CBoolean v, HSValueState state)
{
    vs->raw.as_bool = (HS_CBoolean)(v == 0 ? 0 : 1);
    vs->type = HS_TYPE_BOOL;
    vs->value_state = state;
}

void hs_hsvalue_construct_int(HSValue *vs, HS_CInteger v, HSValueState state)
{
    vs->raw.as_int = v;
    vs->type = HS_TYPE_INT;
    vs->value_state = state;
}

void hs_hsvalue_construct_float(HSValue *vs, HS_CFloat v, HSValueState state)
{
    vs->raw.as_float = v;
    vs->type = HS_TYPE_FLOAT;
    vs->value_state = state;
}
