#include "HSConstant.h"
#include "../../back/value/HSConstruct.h"

HSConstant::HSConstant()
{
    set_as_null();
}

void HSConstant::set_as_null()
{  
    hs_hsvalue_getnull();
}

void HSConstant::set_as_int(HS_CInteger v)
{
    hs_hsvalue_construct_int(&value, v, HS_VS_CONSTANT);
}

void HSConstant::set_as_float(HS_CFloat v)
{
    hs_hsvalue_construct_float(&value, v, HS_VS_CONSTANT);
}

void HSConstant::set_as_bool(HS_CBoolean v)
{
    hs_hsvalue_construct_bool(&value, v, HS_VS_CONSTANT);
}

HSValue *HSConstant::get_backvalue()
{
    return &value;
}

std::string HSConstant::repr()
{
    switch (value.type)
    {
    case HS_TYPE_NULL:
        return "null";
    case HS_TYPE_BOOL:
        return value.raw.as_bool ? "true" : "false";
    case HS_TYPE_INT:
        return std::to_string(value.raw.as_int);
    case HS_TYPE_FLOAT:
        return std::to_string(value.raw.as_float) + "f";
    default:
        break;
    }
}

HSConstant::~HSConstant()
{
}
