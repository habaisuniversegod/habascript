#pragma once
#include "../../HSGlobals.h"
#include <string>

class HSNode {
protected:
    int line;
    int module_id;
public:
    HSNode();
    virtual ~HSNode() = 0;

    void set_line(int line);
    int get_line();
    void set_module_id(int module_id);
    int get_module_id();

    virtual std::string repr();
};
