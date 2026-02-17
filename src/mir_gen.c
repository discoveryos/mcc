#include <stdio.h>
#include <stdarg.h>
#include "mir_gen.h"

static FILE *out;

// Emit single line
static void mir_emit(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(out, fmt, args);
    fprintf(out,"\n");
    va_end(args);
}

// Recursive MIR generation (simplified)
static void gen_node(ASTNode *n) {
    if(!n) return;

    switch(n->kind) {
        case AST_NUMBER:
            mir_emit("    mov rax, %s", n->value);
            break;
        case AST_ASSIGN:
            gen_node(n->right);
            mir_emit("    mov [%s], rax", n->left->value);
            break;
        case AST_BINOP:
            gen_node(n->left);
            mir_emit("    push rax");
            gen_node(n->right);
            mir_emit("    pop rbx");
            if(n->value[0]=='+') mir_emit("    add rax, rbx");
            else if(n->value[0]=='-') mir_emit("    sub rax, rbx");
            break;
        case AST_BLOCK:
            for(ASTNode *cur=n->left; cur; cur=cur->right) gen_node(cur);
            break;
        case AST_RETURN:
            gen_node(n->left);
            mir_emit("    ret");
            break;
        default:
            break; // add more nodes as needed
    }
}

void mir_generate(ASTNode *root, const char *asm_filename) {
    out = fopen(asm_filename,"w");
    if(!out){ perror("fopen"); return; }

    fprintf(out,".text\n");
    fprintf(out,".global main\n");
    fprintf(out,"main:\n");
    gen_node(root);
    fclose(out);
}

