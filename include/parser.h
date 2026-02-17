#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
#include "ast.h"
#include "symtab.h"

typedef struct {
    Lexer *lexer;
    Token current;
} Parser;

void parser_init(Parser *parser, Lexer *lexer);
ASTNode *parse_program(Parser *parser, Scope **scope);
#endif

