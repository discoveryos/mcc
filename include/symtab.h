#ifndef SYMTAB_H
#define SYMTAB_H

typedef struct Sym {
    char *name;       // variable or function name
    char *type;       // type string: "int", "void"
    struct Sym *next; // linked list in scope
} Sym;

typedef struct Scope {
    Sym *symbols;        // head of linked list
    struct Scope *parent; // parent scope
} Scope;

// Scope management
Scope *scope_push(Scope *parent);    // enter new scope
Scope *scope_pop(Scope *scope);      // exit scope

// Symbol management
void sym_add(Scope *scope, const char *name, const char *type); // add symbol
Sym *sym_find(Scope *scope, const char *name);                  // lookup

#endif

