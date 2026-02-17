#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typecheck.h"

static void type_error(const char *msg) {
    fprintf(stderr,"Type Error: %s\n",msg);
    exit(1);
}

void type_check(ASTNode *node, Scope *scope) {
    if(!node) return;

    switch(node->kind) {
        case AST_NUMBER:
            node->type = "int";
            break;
        case AST_IDENT: {
            Sym *s = sym_find(scope,node->value);
            if(!s) type_error(node->value);
            node->type = s->type;
            break;
        }
        case AST_DECL:
            sym_add(scope,node->right->value,node->left->value);
            node->type = node->left->value;
            break;
        case AST_ASSIGN:
            type_check(node->left,scope);
            type_check(node->right,scope);
            if(strcmp(node->left->type,node->right->type)!=0)
                type_error("Assignment type mismatch");
            node->type = node->left->type;
            break;
        case AST_BINOP:
            type_check(node->left,scope);
            type_check(node->right,scope);
            if(strcmp(node->left->type,"int")!=0 || strcmp(node->right->type,"int")!=0)
                type_error("Binary operation requires int operands");
            node->type = "int";
            break;
        case AST_RETURN:
            type_check(node->left,scope);
            node->type = node->left->type;
            break;
        case AST_BLOCK:
            for(ASTNode *cur=node->left;cur;cur=cur->right)
                type_check(cur,scope);
            break;
        default:
            break; // extend for functions, if/while/for
    }

    if(node->right) type_check(node->right,scope);
}
