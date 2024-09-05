#pragma once
#include "../../../HSGlobals.h"
#include "../HSNode.h"
#include "HSExpressionTypes.h"
#include <string>

class HSExpression: public HSNode {
protected:
    HSExpressionType type;
public:
    HSExpression();
    virtual ~HSExpression() = 0;
    
    HSExpressionType get_type();
    virtual std::string repr();
};