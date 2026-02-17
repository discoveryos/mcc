#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "ast.h"
#include "symtab.h"

// Check types of AST nodes recursively
void type_check(ASTNode *node, Scope *scope);

#endif
