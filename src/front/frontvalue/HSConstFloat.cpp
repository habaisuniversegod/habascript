#include "HSConstFloat.h"

HSConstFloat::HSConstFloat(double v)
{
    type = HS_TYPE_FLOAT;
    value = v;
    HSConst::add_constant(this);
}

HSConstFloat::~HSConstFloat()
{
}

double HSConstFloat::get_value()
{
    return value;
}

void HSConstFloat::set_value(double v)
{
    value = v;
}

std::string HSConstFloat::repr()
{
    return std::to_string(value) + "f";
}

void HSConstFloat::pack(std::vector<uint8_t> &v)
{
    v.push_back((uint8_t)type);
    HS_REPEAT(8, v.push_back(0));
    *(double*)&v.data()[v.size() - 8] = value;
}

bool HSConstFloat::operator==(const HSConst &r)
{
    if (r.get_type() != type)
        return false;
    HSConstFloat* asfloat = (HSConstFloat*)&r;
    return value == asfloat->get_value();
}
