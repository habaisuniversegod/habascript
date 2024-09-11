#pragma once
#include "../../back/value/HSValue.h"

#include <string>

class HSConstant
{
    HSValue value;
public:
    HSConstant();
    ~HSConstant();

    void set_as_null();
    void set_as_bool(HS_CBoolean v);
    void set_as_int(HS_CInteger v);
    void set_as_float(HS_CFloat v);

    HSValue* get_backvalue();
    std::string repr();

};
