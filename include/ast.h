#ifndef AST_H
#define AST_H

typedef enum {
    AST_NUMBER,
    AST_IDENT,
    AST_DECL,
    AST_ASSIGN,
    AST_BINOP,
    AST_RETURN,
    AST_FUNC,
    AST_BLOCK,
    AST_IF,
    AST_WHILE,
    AST_FOR
} ASTKind;

typedef struct ASTNode {
    ASTKind kind;
    char *value;
    struct ASTNode *left;
    struct ASTNode *right;
    char *type;
} ASTNode;

ASTNode *ast_create(ASTKind kind, const char *value);

#endif

