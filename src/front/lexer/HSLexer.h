#pragma once
#include "../../HSGlobals.h"
#include "HSToken.h"
#include "HSSpecialTokens.h"
#include "../reader/HSReadSource.h"
#include <string>
#include <vector>

class HSLexer {    
    int64_t eol_counter = 0;
    int64_t position = 0;
    int module_id = 0;

    std::string text;
    std::vector<HSToken> tokens{};

    bool is_idchar(char c);
    bool is_intchar(char c);

    char get(int disp = 0);
    void next(int disp = 1);

    void process_number();
    void process_string_literal();
    void process_name();
    void process_symbol_operator();
    void process_space_characters();
    void skip_comment();

public:
    HSLexer();
    ~HSLexer();

    void reload(const std::string& text, int module_id);
    void process();
    const std::vector<HSToken>& get_tokens() const;
    void clear();
};