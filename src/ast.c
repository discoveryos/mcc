#include "ast.h"
#include <stdlib.h>
#include <string.h>

ASTNode *ast_create(ASTKind kind, const char *value) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->kind = kind;
    n->value = value ? strdup(value) : NULL;
    n->left = n->right = NULL;
    n->type = NULL;
    return n;
}

