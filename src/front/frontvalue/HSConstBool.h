#pragma once

#include "../../HSGlobals.h"
#include "../../HSTypes.h"

#include "HSConst.h"

class HSConstBool final : public HSConst
{
    bool value;
public:
    HSConstBool(bool v);
    virtual ~HSConstBool() override;

    bool get_value();
    void set_value(bool v);

    virtual std::string repr() override;
    virtual void pack(std::vector<uint8_t>& v) override;
    virtual bool operator==(const HSConst& r) override;
};
