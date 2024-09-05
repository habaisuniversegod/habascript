#include "HSTranslationModule.h"

int HSTranslationModule::last_id = 0;

HSTranslationModule::HSTranslationModule()
{
    id = last_id++;
}

HSTranslationModule::~HSTranslationModule()
{
}

void HSTranslationModule::set_path(const std::string &path)
{
    this->path = path;
}

void HSTranslationModule::process_reader(HSReadSource *reader)
{
    this->reader = reader;
    reader->read(path, id);
}

void HSTranslationModule::process_lexer(HSLexer *lexer)
{
    lexer->reload(reader->get_text(), id);
    lexer->process();
}

int HSTranslationModule::get_id()
{
    return id;
}

const std::string &HSTranslationModule::get_path() const
{
    return path;
}

const std::string &HSTranslationModule::get_text() const
{
    return reader->get_text();
}

const std::vector<HSToken> &HSTranslationModule::get_tokens() const
{
    return lexer->get_tokens();
}
