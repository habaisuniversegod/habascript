#pragma once
#include "../../../HSGlobals.h"
#include "HSExpression.h"
#include "../../frontvalue/HSConst.h"

class HSAtomicExpression final: public HSExpression {
    HSConst* raw_value;
public:
    HSAtomicExpression(HSConst* value);
    ~HSAtomicExpression() override;

    HSConst* raw();
    virtual std::string repr() override;
};