#pragma once
#include "../../../HSGlobals.h"
#include "HSExpression.h"

class HSAtomicExpression final: public HSExpression {
    double raw_value;
public:
    HSAtomicExpression(double value);
    ~HSAtomicExpression() override;

    double& raw();
    virtual std::string repr() override;
    virtual void accept(HSTraverseVisitor&);
};