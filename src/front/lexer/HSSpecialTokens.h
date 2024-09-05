#pragma once
#include <unordered_map>
#include <string>
#include "../../HSGlobals.h"
#include "HSTokenType.h"

#define HS_OPER_PLUS(c) ((c) == '+')
#define HS_OPER_MINUS(c) ((c) == '-')
#define HS_OPER_STAR(c) ((c) == '*')
#define HS_OPER_SLASH(c) ((c) == '/')
#define HS_OPER_PERCENT(c) ((c) == '%')
#define HS_OPER_ASSIGN(c) ((c) == '=')
#define HS_OPER_LPAR(c) ((c) == '(')
#define HS_OPER_RPAR(c) ((c) == ')')
#define HS_OPER_LESS(c) ((c) == '<')
#define HS_OPER_GRE(c) ((c) == '>')
#define HS_OPER_COMMA(c) ((c) == ',')
#define HS_OPER_DOT(c) ((c) == '.')

#define HS_OPER_EQUAL(c,d) ((c) == '=' && (d) == '=')
#define HS_OPER_LESSEQ(c,d) ((c) == '>' && (d) == '=')
#define HS_OPER_GREEQ(c,d) ((c) == '<' && (d) == '=')
#define HS_OPER_NEQ(c,d) ((c) == '!' && (d) == '=')

extern const std::unordered_map<std::string, HSTokenType> HS_KEYWORDS;

extern HSTokenType hs_is_keyword(const std::string& value);