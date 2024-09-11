#include "HSNode.h"

HSNode::HSNode()
{
}

HSNode::~HSNode()
{
}

void HSNode::set_line(int line)
{
    this->line = line;
}

int HSNode::get_line()
{
    return line;
}

void HSNode::set_module_id(int module_id)
{
    this->module_id = module_id;
}

int HSNode::get_module_id()
{
    return module_id;
}

std::string HSNode::repr()
{
    return "<HSNode>";
}
