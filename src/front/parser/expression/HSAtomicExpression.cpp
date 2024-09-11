#include "HSAtomicExpression.h"

HSAtomicExpression::HSAtomicExpression(HSConstant value)
{
    raw_value = value;
    type = EX_ATOM;
}

HSAtomicExpression::~HSAtomicExpression()
{
}

HSConstant &HSAtomicExpression::raw()
{
    return raw_value;
}

std::string HSAtomicExpression::repr()
{
    return "(" + raw_value.repr() + ")";
}

void HSAtomicExpression::accept(HSTraverseVisitor &)
{
}
