#include "HSUnaryExpression.h"

HSUnaryExpression::HSUnaryExpression(HSExpression *operand, HSTokenType operation)
{
    this->operand = operand;
    this->operation = operation;
    type = EX_UNARY;
}

HSUnaryExpression::~HSUnaryExpression()
{
    delete operand;
}

std::string HSUnaryExpression::repr()
{
    return "(" + HS_TOKENTYPE_NAMES[operation] + " " + operand->repr() + ")";
}
