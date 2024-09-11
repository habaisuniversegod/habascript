/*
HSValue default constructors
* May be used in front (C++)
*/

#pragma once

#include "HSValue.h"

#ifdef __cplusplus
extern "C" {
#endif

void hs_hsvalue_construct_bool(HSValue* vs, HS_CBoolean v, HSValueState state);
void hs_hsvalue_construct_int(HSValue* vs, HS_CInteger v, HSValueState state);
void hs_hsvalue_construct_float(HSValue* vs, HS_CFloat v, HSValueState state);

#ifdef __cplusplus
}
#endif