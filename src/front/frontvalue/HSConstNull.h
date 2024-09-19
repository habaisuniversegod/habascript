#pragma once

#include "../../HSGlobals.h"
#include "../../HSTypes.h"

#include "HSConst.h"
class HSConstNull final : public HSConst
{

public:
    HSConstNull();
    virtual ~HSConstNull() override;

    virtual std::string repr() override;
    virtual void pack(std::vector<uint8_t>& v) override;
    virtual bool operator==(const HSConst& r) override;
};
