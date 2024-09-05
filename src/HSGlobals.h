#pragma once

#include <stdio.h>
#include <setjmp.h>

extern jmp_buf hs_front_exitenv;

// #define HS_COMPILE_DEBUG_METHODS

#define HS_TEXTTERM '\0'
#define HS_TEXTEOL '\n'
#define HS_FLOATDELIM '.'
#define HS_STRINGQUOTE '"'
#define HS_COMMENT '#'

#define HS_EXIT(code) exit(code)
#define HS_FASTWHILE(cond, body) if(cond){do{body}while(cond);}