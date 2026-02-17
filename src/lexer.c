#include "lexer.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

void lexer_init(Lexer *lexer, const char *src) {
    lexer->src = src;
    lexer->pos = 0;
}

Token lexer_next(Lexer *lexer) {
    Token t = {TOK_EOF, ""};
    const char *s = lexer->src + lexer->pos;
    while (isspace(*s)) s++, lexer->pos++;

    if (*s == '\0') return t;

    if (isdigit(*s)) {
        int i = 0;
        while (isdigit(s[i])) t.text[i] = s[i], i++;
        t.text[i] = 0;
        t.type = TOK_NUMBER;
        lexer->pos += i;
        return t;
    }

    if (isalpha(*s) || *s=='_') {
        int i=0;
        while (isalnum(s[i])||s[i]=='_') t.text[i]=s[i], i++;
        t.text[i]=0;
        t.type = TOK_IDENT;
        lexer->pos += i;
        return t;
    }

    t.text[0] = *s;
    t.text[1] = 0;
    t.type = TOK_OPERATOR;
    lexer->pos++;
    return t;
}

