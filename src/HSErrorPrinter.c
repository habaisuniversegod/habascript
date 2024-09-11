#include "HSErrorPrinter.h"

char hs_err_buffer[HS_ERRORMSG_BUF_SIZE];

void hs_front_err(int code, int line, int module_id, const char* maj, const char* min_, int dummy)
{
    printf("HabaScript fucks u in ur ass 8=D---\n(%d:%d) %shs.%s.%s: %s%s\n",
    module_id, line, HS_ANSI_ERROR_COLOR, maj, min_, hs_err_buffer, HS_ANSI_RESET);
    longjmp(hs_front_exitenv, code);
}