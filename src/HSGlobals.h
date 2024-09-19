#pragma once

#include <stdio.h>
#include <setjmp.h>
#include <stdint.h>

extern jmp_buf hs_front_exitenv;

// #define HS_COMPILE_DEBUG_METHODS

// Enable this definition if target architecture is big-endian
// #define BIG_ENDIAN

#define HS_TEXTTERM '\0'
#define HS_TEXTEOL '\n'
#define HS_FLOATDELIM '.'
#define HS_STRINGQUOTE '"'
#define HS_COMMENT '#'

typedef uint32_t HS_CSizeT;
typedef unsigned char HS_CharT;

#define HS_EXIT(code) exit(code)
#define HS_FASTWHILE(cond, body) if(cond){do{body}while(cond);}
#define HS_REPEAT(times, body) for(size_t i=0;i<(times);i++){body;}
#define HS_MALLOCSIZED(type, n) malloc((n) * (sizeof(type)))
#define HS_ASSERT(cond, act) if(!(cond)) {act;}