#ifndef MIR_GEN_H
#define MIR_GEN_H

#include "ast.h"

/*
 * MIR (Micro Intermediate Representation) generator
 * Converts AST to x86-64 assembly
 */

// Generate MIR/Assembly from AST root
void mir_generate(ASTNode *root, const char *asm_filename);

#endif
