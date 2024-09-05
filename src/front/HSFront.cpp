#include "../HSGlobals.h"
#include "HSTranslationModule.h"

#include <unistd.h>

#include "parser/expression/HSAllExpressions.h"

jmp_buf hs_front_exitenv;

void terminate(int code){
    printf("Front exit with %d\n", code);
    HS_EXIT(code);
}

int main(int argc, char** argv){
    bool displayTokens = false;
    bool displayModuleInfo = false;

    int optarg;
    while ((optarg = getopt(argc, argv, "MT")) != -1){
        switch (optarg)
        {
            case 'T': displayTokens = true; break;
            case 'M': displayModuleInfo = true; break;
        }
    }

    int frontcode = setjmp(hs_front_exitenv);
    if (frontcode) terminate(frontcode);

    HSReadSource reader;
    HSLexer lexer;

    HSTranslationModule main_program;
    main_program.set_path(argv[optind]);
    main_program.process_reader(&reader);
    main_program.process_lexer(&lexer);

    if (displayModuleInfo){
        printf("-------------------------------------------\nModule %d: '%s'\n-------------------------------------------\n%s\n", main_program.get_id(), main_program.get_path().c_str(), main_program.get_text().c_str());
        if (displayTokens){
            for (auto i: main_program.get_tokens()){
                i.repr();
            }
        }
    }

    terminate(0);
}