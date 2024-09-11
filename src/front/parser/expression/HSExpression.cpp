#include "HSExpression.h"

HSExpression::HSExpression()
{
    type = EX_NULL;
}

HSExpression::~HSExpression()
{
}

HSExpressionType HSExpression::get_type()
{
    return type;
}
