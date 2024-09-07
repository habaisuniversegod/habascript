#pragma once
#include "../../HSGlobals.h"
#include "../lexer/HSLexer.h"
#include "expression/HSExpression.h"

class HSParser
{
    static const HSToken HS_CONST_EOF;

    int16_t position;
    int16_t eol_counter;
    int module_id;
    std::vector<HSToken> input_tokens;
    HSNode* root;

    const HSToken& get(int disp = 0);
    void next(int disp = 1);
    bool match(HSTokenType type, const std::string& value = "", bool skip_eol = true);
    void consume(HSTokenType type);

    HSExpression* parse_expression();
    HSExpression* parse_plusminus();
    HSExpression* parse_multdiv();
    HSExpression* parse_prefixopers();
    HSExpression* parse_atom();

public:
    HSParser();
    ~HSParser();

    void reload(const std::vector<HSToken>& input_tokens, int module_id);
    void process();
    void clear();

    HSNode* get_root();
};