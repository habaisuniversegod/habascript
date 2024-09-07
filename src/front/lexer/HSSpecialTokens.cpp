#include "HSSpecialTokens.h"

const std::unordered_map<std::string, HSTokenType> HS_KEYWORDS = 
{
    {"if", TOK_IF},
    {"elif", TOK_ELIF},
    {"else", TOK_ELSE},
    {"print", TOK_PRINT},
    {"while", TOK_WHILE},
    {"break", TOK_BREAK},
    {"continue", TOK_CONTINUE},
    {"do", TOK_DO},
    {"od", TOK_OD},
    {"and", TOK_AND},
    {"or", TOK_OR},
    {"not", TOK_NOT},
};

HSTokenType hs_is_keyword(const std::string& value){
    if (HS_KEYWORDS.count(value))
        return HS_KEYWORDS.at(value);
    return TOK_ID;
}