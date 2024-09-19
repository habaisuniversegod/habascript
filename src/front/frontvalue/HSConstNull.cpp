#include "HSConstNull.h"

HSConstNull::HSConstNull()
{
    type = HS_TYPE_NULL;
}

HSConstNull::~HSConstNull()
{
}

std::string HSConstNull::repr()
{
    return "null";
}

void HSConstNull::pack(std::vector<uint8_t> &v)
{
}

bool HSConstNull::operator==(const HSConst &r)
{
    return r.get_type() == type;
}
