#pragma once
#include "../../../HSGlobals.h"
#include "HSExpression.h"
#include "../../lexer/HSTokenType.h"

class HSBinaryExpression final: public HSExpression {
    HSExpression* left;
    HSExpression* right;
    HSTokenType operation;
    
public:
    HSBinaryExpression(HSExpression* left, HSExpression* right, HSTokenType operation);
    ~HSBinaryExpression() override;

    virtual std::string repr() override;
    virtual void accept(HSTraverseVisitor&);
};