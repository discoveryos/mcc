#include <stdio.h>
#include "commands.h"
#include "mt.h"  // Micro toolchain compile function

int main(int argc, char **argv) {
    char *src_file;
    char *exe_file;

    // Use commands.c to parse CLI arguments
    if (!parse_commands(argc, argv, &src_file, &exe_file)) {
        return 0; // Either --version, --help, or error
    }

    // Compilation workflow
    printf("MCC: Compiling '%s' -> '%s'\n", src_file, exe_file);
    mt_compile(src_file, exe_file);
    printf("MCC: Compilation finished.\n");

    return 0;
}

