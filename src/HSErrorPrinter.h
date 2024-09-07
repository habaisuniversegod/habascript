#pragma once

#include "HSGlobals.h"
#include <string>
#include <stdio.h>

#define HS_ANSI_ERROR_COLOR "\x1b[31;1m"
#define HS_ANSI_RESET "\x1b[0m"
#define HS_ERRORMSG_BUF_SIZE 4096

#define HS_ERR_MAJ_READER "reader"
#define HS_ERR_MAJ_LEXER "lexer"
#define HS_ERR_MAJ_PARSER "parser"
#define HS_ERR_MAJ_FRONTCHECKER "frontcheck"
#define HS_ERR_MAJ_CLEANUP "cleanup"

#define HS_ERR_MIN_SRCREADERR "srcOpenError"
#define HS_ERR_MIN_SYNTAXERR "syntaxErr"

extern char hs_err_buffer[];

void hs_front_err(int code, int line, int module_id, const std::string& maj, const std::string& min_, int dummy);

#define HS_ERR_SRCREADERROR(l,m, filename) hs_front_err(-2, l, m, HS_ERR_MAJ_READER, HS_ERR_MIN_SRCREADERR, snprintf(hs_err_buffer, HS_ERRORMSG_BUF_SIZE, "Cannot open source '%s'", filename))
#define HS_ERR_STRINGNOTCLOSED(l,m) hs_front_err(-3, l, m, HS_ERR_MAJ_LEXER, HS_ERR_MIN_SYNTAXERR, snprintf(hs_err_buffer, HS_ERRORMSG_BUF_SIZE, "Unexpected EOF while string parsing (string not closed)"))
#define HS_ERR_UNKNOWNCHARACTERWHILELX(l,m,ch) hs_front_err(-4, l, m, HS_ERR_MAJ_LEXER, HS_ERR_MIN_SYNTAXERR, snprintf(hs_err_buffer, HS_ERRORMSG_BUF_SIZE, "Unrecognized operator '%c'", ch))
#define HS_ERR_UNEXPECTEDTOK(l,m,toktype) hs_front_err(-5, l, m, HS_ERR_MAJ_PARSER, HS_ERR_MIN_SYNTAXERR, snprintf(hs_err_buffer, HS_ERRORMSG_BUF_SIZE, "Unexpected token '%s'", toktype))