#include "HSConstInt.h"

HSConstInt::HSConstInt(int64_t v)
{
    type = HS_TYPE_INT;
    value = v;
    HSConst::add_constant(this);
}

HSConstInt::~HSConstInt()
{
}

int64_t HSConstInt::get_value()
{
    return value;
}

void HSConstInt::set_value(int64_t v)
{
    value = v;
}

std::string HSConstInt::repr()
{
    return std::to_string(value);
}

void HSConstInt::pack(std::vector<uint8_t> &v)
{
    v.push_back((uint8_t)type);
    HS_REPEAT(8, v.push_back(0));
    *(int64_t*)&v.data()[v.size() - 8] = value;
}

bool HSConstInt::operator==(const HSConst &r)
{
    if (r.get_type() != type)
        return false;
    HSConstInt* asint = (HSConstInt*)&r;
    return value == asint->get_value();
}
