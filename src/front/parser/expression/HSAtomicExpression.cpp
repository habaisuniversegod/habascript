#include "HSAtomicExpression.h"

HSAtomicExpression::HSAtomicExpression(HSConst* value)
{
    raw_value = value;
    type = EX_ATOM;
}

HSAtomicExpression::~HSAtomicExpression()
{
    delete raw_value;
}

HSConst* HSAtomicExpression::raw()
{
    return raw_value;
}

std::string HSAtomicExpression::repr()
{
    return "(" + raw_value->repr() + ")";
}