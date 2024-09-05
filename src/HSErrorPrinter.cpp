#include "HSErrorPrinter.h"

char hs_err_buffer[HS_ERRORMSG_BUF_SIZE];

void hs_front_err(int code, int line, int module_id, const std::string& maj, const std::string& min_, int dummy)
{
    printf("HabaScript fucks u in ur ass 8=D---\n(%d:%d) %shs.%s.%s: %s%s\n",
    module_id, line, HS_ANSI_ERROR_COLOR, maj.c_str(), min_.c_str(), hs_err_buffer, HS_ANSI_RESET);
    longjmp(hs_front_exitenv, code);
}