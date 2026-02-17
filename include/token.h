#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    TOK_EOF = 0,
    TOK_INT,
    TOK_RETURN,
    TOK_IDENT,
    TOK_NUMBER,
    TOK_LPAREN, TOK_RPAREN,
    TOK_LBRACE, TOK_RBRACE,
    TOK_SEMI,
    TOK_PLUS, TOK_MINUS, TOK_STAR, TOK_SLASH
} TokenKind;

typedef struct {
    TokenKind kind;
    const char *start;
    int length;
    int value;
} Token;

#endif

