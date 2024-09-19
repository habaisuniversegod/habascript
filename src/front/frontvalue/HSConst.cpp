#include "HSConst.h"

std::vector<HSConst*> HSConst::constants = {};

void HSConst::add_constant(HSConst *c)
{
    for (HSConst* i: constants){
        if (*i == *c)
            return;
    }
    constants.push_back(c);
    printf("new constant added (id=%d, type=%d, value=%s)\n", constants.size() - 1, c->get_type(), c->repr().c_str());
}

HSConst::HSConst()
{
}

HSConst::~HSConst()
{
}

std::string HSConst::repr(){
}

void HSConst::pack(std::vector<uint8_t>& v){
}

bool HSConst::operator==(const HSConst &r)
{
}

HSType HSConst::get_type() const
{
    return type;
}
