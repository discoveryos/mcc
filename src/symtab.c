#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symtab.h"

Scope *scope_push(Scope *parent) {
    Scope *s = malloc(sizeof(Scope));
    s->symbols = NULL;
    s->parent = parent;
    return s;
}

Scope *scope_pop(Scope *scope) {
    Sym *cur = scope->symbols;
    while(cur) {
        Sym *tmp = cur;
        cur = cur->next;
        free(tmp->name);
        free(tmp->type);
        free(tmp);
    }
    Scope *parent = scope->parent;
    free(scope);
    return parent;
}

void sym_add(Scope *scope, const char *name, const char *type) {
    Sym *s = malloc(sizeof(Sym));
    s->name = strdup(name);
    s->type = strdup(type);
    s->next = scope->symbols;
    scope->symbols = s;
}

Sym *sym_find(Scope *scope, const char *name) {
    for(Scope *s = scope; s; s = s->parent) {
        for(Sym *cur = s->symbols; cur; cur = cur->next) {
            if(strcmp(cur->name,name)==0) return cur;
        }
    }
    return NULL;
}

