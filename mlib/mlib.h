#ifndef MLIB_H
#define MLIB_H

#include <stddef.h>

// Memory
void *m_malloc(size_t size);
void m_free(void *ptr);

// I/O
int m_print(const char *str);
int m_print_int(int x);

// String
size_t m_strlen(const char *s);
char *m_strdup(const char *s);

// File I/O
int m_file_exists(const char *filename);

#endif
