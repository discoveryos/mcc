#include "mt.h"
#include "parser.h"
#include "ast.h"
#include "typecheck.h"
#include "mir_gen.h"
#include "mlib.h"   // for linking basic library functions
#include <stdio.h>
#include <stdlib.h>

// Compile a C source file into an executable
void mt_compile(const char *src_file, const char *exe_file) {
    printf("[MT] Starting compilation of '%s'\n", src_file);

    // ----------------------
    // 1. Parse the source
    // ----------------------
    ASTNode *program = parse_source(src_file);
    if (!program) {
        fprintf(stderr, "[MT] Parsing failed.\n");
        exit(1);
    }
    printf("[MT] Parsing completed.\n");

    // ----------------------
    // 2. Type check the AST
    // ----------------------
    typecheck_ast(program);
    printf("[MT] Type checking completed.\n");

    // ----------------------
    // 3. Generate MIR
    // ----------------------
    MIRNode *mir = generate_mir(program);
    if (!mir) {
        fprintf(stderr, "[MT] MIR generation failed.\n");
        exit(1);
    }
    printf("[MT] MIR generation completed.\n");

    // ----------------------
    // 4. Output assembly file
    // ----------------------
    const char *asm_file = "out.s";
    if (!mir_generate_asm(mir, asm_file)) {
        fprintf(stderr, "[MT] Failed to generate assembly.\n");
        exit(1);
    }
    printf("[MT] Assembly written to '%s'.\n", asm_file);

    // ----------------------
    // 5. Compile assembly to object file
    // ----------------------
    const char *obj_file = "out.o";
    char cmd[512];
    snprintf(cmd, sizeof(cmd), "gcc -c %s -o %s", asm_file, obj_file);
    if (system(cmd) != 0) {
        fprintf(stderr, "[MT] Failed to compile assembly.\n");
        exit(1);
    }
    printf("[MT] Object file generated: '%s'\n", obj_file);

    // ----------------------
    // 6. Link object file with mlib
    // ----------------------
    snprintf(cmd, sizeof(cmd), "gcc %s %s/mlib.o -o %s", obj_file, "mlib", exe_file);
    if (system(cmd) != 0) {
        fprintf(stderr, "[MT] Linking failed.\n");
        exit(1);
    }
    printf("[MT] Executable generated: '%s'\n", exe_file);

    // ----------------------
    // Done
    // ----------------------
    printf("[MT] Compilation finished successfully.\n");
}

