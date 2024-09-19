#pragma once

#include "../../HSGlobals.h"
#include "../../HSTypes.h"

#include "HSConst.h"

class HSConstInt final : public HSConst
{
    int64_t value;
public:
    HSConstInt(int64_t v);
    virtual ~HSConstInt() override;

    int64_t get_value();
    void set_value(int64_t v);

    virtual std::string repr() override;
    virtual void pack(std::vector<uint8_t>& v) override;
    virtual bool operator==(const HSConst& r) override;
};
