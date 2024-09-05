#include "HSAtomicExpression.h"

HSAtomicExpression::HSAtomicExpression(double value)
{
    raw_value = value;
    type = EX_ATOM;
}

HSAtomicExpression::~HSAtomicExpression()
{
}

double &HSAtomicExpression::raw()
{
    return raw_value;
}

std::string HSAtomicExpression::repr()
{
    return std::to_string(raw_value) + "f";
}

void HSAtomicExpression::accept(HSTraverseVisitor &)
{
}
