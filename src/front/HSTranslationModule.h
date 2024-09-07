#pragma once
#include <string>
#include <vector>
#include "reader/HSReadSource.h"
#include "lexer/HSLexer.h"
#include "parser/HSNode.h"
#include "parser/HSParser.h"

class HSTranslationModule
{
    int id;
    std::string path;
    HSReadSource* reader;
    HSLexer* lexer;
    HSParser* parser;

    static int last_id;
public:
    HSTranslationModule();
    ~HSTranslationModule();

    void set_path(const std::string& path);
    void process_reader(HSReadSource* reader);
    void process_lexer(HSLexer* lexer);
    void process_parser(HSParser* parser);

    int get_id();
    const std::string& get_path() const;
    const std::string& get_text() const;
    const std::vector<HSToken>& get_tokens() const;
    HSNode* get_root() const;

    void clear();
};
