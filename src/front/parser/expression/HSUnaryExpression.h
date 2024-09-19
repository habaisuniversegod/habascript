#pragma once
#include "../../../HSGlobals.h"
#include "HSExpression.h"
#include "../../lexer/HSTokenType.h"

class HSUnaryExpression final: public HSExpression {
    HSExpression* operand;
    HSTokenType operation;
    
public:
    HSUnaryExpression(HSExpression* operand, HSTokenType operation);
    ~HSUnaryExpression() override;

    virtual std::string repr() override;
};