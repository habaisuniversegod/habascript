#pragma once

#include "../../HSGlobals.h"
#include "HSTokenType.h"
#include <string>

class HSToken {
public:
    HSTokenType type;
    std::string value;
    int64_t line;
    int source_id;

    HSToken();
    HSToken(HSTokenType type, const std::string& value = "", int64_t line = 0, int source_id = -1);

    void repr();
};