#pragma once
#include "../../../HSGlobals.h"
#include "HSExpression.h"
#include "../../frontvalue/HSConstant.h"

class HSAtomicExpression final: public HSExpression {
    HSConstant raw_value;
public:
    HSAtomicExpression(HSConstant value);
    ~HSAtomicExpression() override;

    HSConstant& raw();
    virtual std::string repr() override;
    virtual void accept(HSTraverseVisitor&);
};