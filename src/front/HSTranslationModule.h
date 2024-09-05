#pragma once
#include <string>
#include <vector>
#include "reader/HSReadSource.h"
#include "lexer/HSLexer.h"
#include "parser/HSNode.h"

class HSTranslationModule
{
    int id;
    std::string path;
    HSReadSource* reader;
    HSLexer* lexer;
    HSNode* ast_root;

    static int last_id;
public:
    HSTranslationModule();
    ~HSTranslationModule();

    void set_path(const std::string& path);
    void process_reader(HSReadSource* reader);
    void process_lexer(HSLexer* lexer);

    int get_id();
    const std::string& get_path() const;
    const std::string& get_text() const;
    const std::vector<HSToken>& get_tokens() const;
};
