#pragma once

#include "../../HSGlobals.h"
#include "../../HSTypes.h"

#include "HSConst.h"

class HSConstFloat final : public HSConst
{
    double value;
public:
    HSConstFloat(double v);
    virtual ~HSConstFloat() override;

    double get_value();
    void set_value(double v);

    virtual std::string repr() override;
    virtual void pack(std::vector<uint8_t>& v) override;
    virtual bool operator==(const HSConst& r) override;
};
