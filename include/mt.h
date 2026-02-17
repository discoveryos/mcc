#ifndef MT_H
#define MT_H

#include <stdio.h>
#include <stdlib.h>

// Forward declarations of AST and MIR structures
struct ASTNode;
struct MIRNode;

// --------------------------
// Micro Toolchain Functions
// --------------------------

// Compile a C source file into an executable
// src_file: input C file
// exe_file: output executable
void mt_compile(const char *src_file, const char *exe_file);

// --------------------------
// Optional helper functions
// --------------------------

// Parse a C file into an AST (defined in parser.c / ast.c)
struct ASTNode* parse_source(const char *src_file);

// Type check the AST (defined in typecheck.c)
void typecheck_ast(struct ASTNode *program);

// Generate MIR from AST (defined in mir_gen.c)
struct MIRNode* generate_mir(struct ASTNode *program);

#endif
