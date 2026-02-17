#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "version.h"

int parse_commands(int argc, char **argv, char **src_file, char **exe_file) {
    if (argc < 2) {
        printf("Usage: %s <source.c> <output_executable>\n", argv[0]);
        printf("       %s --version\n", argv[0]);
        printf("       %s --help\n", argv[0]);
        return 0;
    }

    // Handle --version
    if (strcmp(argv[1], "--version") == 0) {
        printf("MCC (Micro C Compiler) version %s\n", MCC_VERSION);
        printf("Build: %s\n", MCC_BUILD_DATE);
        printf("Platform: %s\n", MCC_PLATFORM);
        printf("%s\n", MCC_ATTRIBUTION);
        return 0;
    }

    // Handle --help
    if (strcmp(argv[1], "--help") == 0) {
        printf("MCC (Micro C Compiler) - usage:\n");
        printf("  %s <source.c> <output_executable>  Compile a C source file\n", argv[0]);
        printf("  %s --version                       Show compiler version\n", argv[0]);
        printf("  %s --help                          Show this help message\n", argv[0]);
        return 0;
    }

    // Default: treat first argument as source, second as executable
    if (argc < 3) {
        printf("Error: missing output executable name\n");
        printf("Usage: %s <source.c> <output_executable>\n", argv[0]);
        return 0;
    }

    *src_file = argv[1];
    *exe_file = argv[2];

    return 1; // Compilation should proceed
}
