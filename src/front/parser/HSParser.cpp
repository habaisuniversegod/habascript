#include "HSParser.h"
#include "../../HSErrorPrinter.h"
#include "expression/HSAllExpressions.h"

extern void terminate(int);
const HSToken HSParser::HS_CONST_EOF = {TOK_EOF, "", -1, -1};

const HSToken &HSParser::get(int disp)
{
    int16_t new_pos = position + disp;
    if (new_pos > input_tokens.size())
        return HS_CONST_EOF;
    return input_tokens.at(new_pos);
}

void HSParser::next(int disp)
{
    position += disp;
}

bool HSParser::match(HSTokenType type, const std::string &value, bool skip_eol)
{
    while (skip_eol && get().type == TOK_EOL){next(); eol_counter++;};

    if (get().type == type && (value == "" || value == get().value)){
        next();
        return true;
    }
    return false;
}

void HSParser::consume(HSTokenType type)
{
    if (!match(type))
        HS_ERR_UNEXPECTEDTOK(eol_counter, module_id, HS_TOKENTYPE_NAMES[type].c_str());
}

HSExpression *HSParser::parse_expression()
{
    return parse_plusminus();
}

HSExpression *HSParser::parse_plusminus()
{
    HSExpression* binop = parse_multdiv();
    while (1){
        if (match(TOK_PLUS) || match(TOK_MINUS)){
            binop = new HSBinaryExpression(binop, parse_multdiv(), get(-1).type);
            continue;
        }
        break;
    }
    return binop;
}

HSExpression *HSParser::parse_multdiv()
{
    HSExpression* binop = parse_prefixopers();
    while (1){
        if (match(TOK_STAR) || match(TOK_SLASH) || match(TOK_PERCENT)){
            binop = new HSBinaryExpression(binop, parse_prefixopers(), get(-1).type);
            continue;
        }
        break;
    }
    return binop;
}

HSExpression *HSParser::parse_prefixopers()
{
    if (match(TOK_MINUS)){
        return new HSUnaryExpression(parse_prefixopers(), TOK_MINUS);
    }
    return parse_atom();
}

HSExpression *HSParser::parse_atom()
{
    if (match(TOK_INT) || match(TOK_FLOAT)){
        return new HSAtomicExpression(atof(get(-1).value.c_str()));
    }
    if (match(TOK_STRING)){
        // TODO: sttrings
        terminate(-1488);
    }
    if (match(TOK_LPAREN)){
        HSExpression* expr = parse_expression();
        consume(TOK_RPAREN);
        return expr;
    }
    HS_ERR_UNEXPECTEDTOK(eol_counter, module_id, HS_TOKENTYPE_NAMES[get().type].c_str());
}

HSParser::HSParser()
{

}

HSParser::~HSParser()
{
}

void HSParser::reload(const std::vector<HSToken> &input_tokens, int module_id)
{
    this->input_tokens = input_tokens;
    this->module_id = 0;
    eol_counter = 1;
    position = 0;
}

void HSParser::process()
{
    HSExpression* expr = parse_expression();
    root = expr;
}

void HSParser::clear()
{
    input_tokens.clear();
    input_tokens.shrink_to_fit();
}

HSNode *HSParser::get_root()
{
    return root;
}
