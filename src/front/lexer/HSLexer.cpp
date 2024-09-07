#include "HSLexer.h"
#include "../../HSErrorPrinter.h"

bool HSLexer::is_idchar(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || is_intchar(c);
}

bool HSLexer::is_intchar(char c)
{
    return c >= '0' && c <= '9';
}

char HSLexer::get(int disp)
{
    uint64_t newpos = position + disp;
    if (newpos >= text.size())
        return HS_TEXTTERM;
    return text.at(newpos);
}

void HSLexer::next(int disp)
{
    position += disp;
}

void HSLexer::process_number()
{
    std::string buffer;
    HSTokenType type = TOK_INT;
    char c;

    while (true){
        c = get();
        if (c == HS_FLOATDELIM){
            type = TOK_FLOAT;
        }
        if (!is_intchar(c)){
            break;
        }
        buffer += c;
        next();
    }
    tokens.push_back(HSToken(type, buffer, eol_counter, module_id));
}

void HSLexer::process_string_literal()
{
    std::string buffer;
    char c;
    next();
    while (true){
        c = get();
        if (c == HS_TEXTTERM)
            HS_ERR_STRINGNOTCLOSED(eol_counter, module_id);
        if (c == HS_STRINGQUOTE){
            next();
            break;
        }
        buffer += c;
        next();
    }
    tokens.push_back(HSToken(TOK_STRING, buffer, eol_counter, module_id));
}

void HSLexer::process_name()
{
    std::string buffer;
    char c;

    while (true){
        c = get();
        if (!is_idchar(c)){
            break;
        }
        buffer += c;
        next();
    }
    tokens.push_back(HSToken(hs_is_keyword(buffer), buffer, eol_counter, module_id));
}

void HSLexer::process_symbol_operator()
{
    char c1 = get(0);
    char c2 = get(1);
    next();
    HSTokenType type = TOK_EOF;

    if (HS_OPER_EQUAL(c1,c2)){ type = TOK_EQ; next();}
    if (HS_OPER_LESSEQ(c1,c2)){ type = TOK_LSEQ; next();}
    if (HS_OPER_GREEQ(c1,c2)){ type = TOK_GREQ; next();}
    if (HS_OPER_NEQ(c1,c2)){ type = TOK_NEQ; next();}

    else if (HS_OPER_PLUS(c1)) type = TOK_PLUS;
    else if (HS_OPER_MINUS(c1)) type = TOK_MINUS;
    else if (HS_OPER_STAR(c1)) type = TOK_STAR;
    else if (HS_OPER_SLASH(c1)) type = TOK_SLASH;
    else if (HS_OPER_PERCENT(c1)) type = TOK_PERCENT;
    else if (HS_OPER_ASSIGN(c1)) type = TOK_ASSIGN;
    else if (HS_OPER_LPAR(c1)) type = TOK_LPAREN;
    else if (HS_OPER_RPAR(c1)) type = TOK_RPAREN;
    else if (HS_OPER_LESS(c1)) type = TOK_LESS;
    else if (HS_OPER_GRE(c1)) type = TOK_GRE;
    else if (HS_OPER_COMMA(c1)) type = TOK_COMMA;
    else if (HS_OPER_DOT(c1)) type = TOK_DOT;

    if (type == TOK_EOF){
        HS_ERR_UNKNOWNCHARACTERWHILELX(eol_counter, module_id, c1);
    }
    tokens.push_back(HSToken(type, "", eol_counter, module_id));
}

void HSLexer::process_space_characters()
{
    char c;
    while (true){
        c = get();
        if (!isspace(c))
            break;
        next();
    }
}

void HSLexer::skip_comment()
{
    char c;
    while (true){
        c = get();
        if (c == HS_TEXTEOL){
            break;
        }
        next();
    }
}

HSLexer::HSLexer()
{
}

HSLexer::~HSLexer()
{
}

void HSLexer::reload(const std::string &text, int module_id)
{
    this->text = text;
    this->module_id = module_id;
    eol_counter = 1;
}

void HSLexer::process()
{
    char c;
    while (true){
        c = get();
        if (c == HS_TEXTTERM) {
            break;
        }
        if (is_intchar(c)){
            process_number();
            continue;
        }
        if (is_idchar(c)){
            process_name();
            continue;
        }
        if (c == HS_TEXTEOL){
            tokens.push_back(HSToken(TOK_EOL, "", eol_counter, module_id));
            eol_counter++;
            next();
            continue;
        }
        if (isspace(c)){
            process_space_characters();
            continue;
        }
        if (c == HS_STRINGQUOTE){
            process_string_literal();
            continue;
        }
        if (c == HS_COMMENT){
            skip_comment();
            continue;
        }
        process_symbol_operator();
    }
    tokens.push_back(HSToken(TOK_EOF, "", eol_counter, module_id));
}

const std::vector<HSToken> &HSLexer::get_tokens() const
{
    return tokens;
}

void HSLexer::clear()
{
    text.clear();
    text.shrink_to_fit();
}
