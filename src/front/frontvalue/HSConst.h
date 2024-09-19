#pragma once

#include "../../HSGlobals.h"
#include "../../HSTypes.h"

#include <string>
#include <vector>

class HSConst
{
protected:
    HSType type = HS_TYPE_NULL;

public:
    static std::vector<HSConst*> constants;
    static void add_constant(HSConst* c);

    HSConst();
    virtual ~HSConst() = 0;

    virtual std::string repr() = 0;
    virtual void pack(std::vector<uint8_t>&) = 0;
    virtual bool operator==(const HSConst& r);

    HSType get_type() const;
};
