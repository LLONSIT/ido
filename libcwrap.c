#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "libp/libp.h"

int __Argc;
char **__Argv;

#define false 0
#define true 1

unsigned char debug_ugen = false;

double _atod(const char *str) {
    return atof(str);
}

int main1(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    __Argc = argc;
    __Argv = argv;
    output.c_file = stdout;
    err.c_file = stderr;
    main1(argc, argv);
    return 0;
}
