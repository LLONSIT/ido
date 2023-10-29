#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "libp/libp.h"

int __Argc;
char **__Argv;
#ifdef UGEN_DEBUG
unsigned char debug_ugen = 1; //0 = false, 1 = true
#else
unsigned char debug_ugen = 0;
#endif

double _atod(const char *str) {
    return atof(str);
}

int main1(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    __Argc = argc;
    __Argv = argv;
    output.c_file = stdout;
    err.c_file = stderr;
//    test_rperror();
    main1(argc, argv);
    return 0;
}
