#include "HSBinaryExpression.h"

HSBinaryExpression::HSBinaryExpression(HSExpression *left, HSExpression *right, HSTokenType operation)
{
    this->left = left;
    this->right = right;
    this->operation = operation;
    type = EX_BINARY;
}

HSBinaryExpression::~HSBinaryExpression()
{
    delete left;
    delete right;
}

std::string HSBinaryExpression::repr()
{
    return "(" + left->repr() + " " + HS_TOKENTYPE_NAMES[operation] + " " + right->repr() + ")";
}