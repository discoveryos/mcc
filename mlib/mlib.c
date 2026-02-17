#include "mlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------ Memory ------------------
void *m_malloc(size_t size) {
    void *ptr = malloc(size);
    if(!ptr){ fprintf(stderr,"mlib: Out of memory\n"); exit(1); }
    return ptr;
}

void m_free(void *ptr) {
    free(ptr);
}

// ------------------ I/O ------------------
int m_print(const char *str) {
    return printf("%s", str);
}

int m_print_int(int x) {
    return printf("%d\n", x);
}

// ------------------ String ------------------
size_t m_strlen(const char *s) {
    size_t len = 0;
    while(s[len]) len++;
    return len;
}

char *m_strdup(const char *s) {
    size_t len = m_strlen(s);
    char *p = m_malloc(len+1);
    for(size_t i=0;i<=len;i++) p[i]=s[i];
    return p;
}

// ------------------ File I/O ------------------
int m_file_exists(const char *filename) {
    FILE *f = fopen(filename,"r");
    if(f) { fclose(f); return 1; }
    return 0;
}
