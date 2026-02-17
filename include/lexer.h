#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOK_EOF,
    TOK_NUMBER,
    TOK_IDENT,
    TOK_KEYWORD,
    TOK_OPERATOR
} TokenType;

typedef struct {
    TokenType type;
    char text[64];
} Token;

typedef struct {
    const char *src;
    int pos;
} Lexer;

void lexer_init(Lexer *lexer, const char *src);
Token lexer_next(Lexer *lexer);

#endif

