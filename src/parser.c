#include "parser.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void parser_init(Parser *parser, Lexer *lexer) {
    parser->lexer = lexer;
    parser->current = lexer_next(lexer);
}

static void advance(Parser *p) { p->current = lexer_next(p->lexer); }

// Example: parse_number
static ASTNode *parse_number(Parser *p) {
    ASTNode *n = ast_create(AST_NUMBER, p->current.text);
    advance(p);
    return n;
}

// Example: parse_ident
static ASTNode *parse_ident(Parser *p) {
    ASTNode *n = ast_create(AST_IDENT, p->current.text);
    advance(p);
    return n;
}

// parse_assignment
static ASTNode *parse_assignment(Parser *p) {
    ASTNode *lhs = parse_ident(p);
    if (strcmp(p->current.text,"=")==0) {
        advance(p);
        ASTNode *rhs = parse_number(p); // simplified: rhs number
        ASTNode *assign = ast_create(AST_ASSIGN,NULL);
        assign->left = lhs;
        assign->right = rhs;
        return assign;
    }
    return lhs;
}

// parse_block
ASTNode *parse_block(Parser *p, Scope **scope) {
    *scope = scope_push(*scope);
    ASTNode *block = ast_create(AST_BLOCK,NULL);
    ASTNode **cur = &block->left;
    advance(p); // consume '{'
    while (strcmp(p->current.text,"}")!=0 && p->current.type!=TOK_EOF) {
        *cur = parse_assignment(p); // simplified
        cur = &(*cur)->right;
    }
    advance(p); // '}'
    *scope = scope_pop(*scope);
    return block;
}

// parse_program
ASTNode *parse_program(Parser *p, Scope **scope) {
    ASTNode *prog = ast_create(AST_BLOCK,NULL);
    ASTNode **cur = &prog->left;
    while(p->current.type!=TOK_EOF) *cur = parse_assignment(p), cur = &(*cur)->right;
    return prog;
}

