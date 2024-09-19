#include "HSConstBool.h"

HSConstBool::HSConstBool(bool v)
{
    type = HS_TYPE_BOOL;
    value = v;
    HSConst::add_constant(this);
}

HSConstBool::~HSConstBool()
{
}

bool HSConstBool::get_value()
{
    return value;
}

void HSConstBool::set_value(bool v)
{
    value = v;
}

std::string HSConstBool::repr()
{
    return value ? "true" : "false";
}

void HSConstBool::pack(std::vector<uint8_t> &v)
{
    v.push_back((uint8_t)type);
    v.push_back((uint8_t)value);
}

bool HSConstBool::operator==(const HSConst &r)
{
    if (r.get_type() != type)
        return false;
    HSConstBool* asbool = (HSConstBool*)&r;
    return value == asbool->get_value();
}
