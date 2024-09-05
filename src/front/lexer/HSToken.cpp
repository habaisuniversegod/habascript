#include "HSToken.h"
#include "../../HSGlobals.h"

HSToken::HSToken()
{
}

HSToken::HSToken(HSTokenType type, const std::string &value, int64_t line, int source_id)
{
    this->type = type;
    this->value = value;
    this->line = line;
    this->source_id = source_id;
}

void HSToken::repr()
{
    printf("%d:%lld: [%s, %s]\n", source_id, line, HS_TOKENTYPE_NAMES[type].c_str(), value.c_str());
}
