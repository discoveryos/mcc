#ifndef MLIB_H
#define MLIB_H

/* Memory Management Functions */
void *malloc(unsigned int size);
void *calloc(unsigned int num, unsigned int size);
void *realloc(void *ptr, unsigned int size);
void free(void *ptr);

/* String Functions */
int strlen(const char *str);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
int strcmp(const char *str1, const char *str2);
char *strncpy(char *dest, const char *src, int n);

/* Math Functions */
int abs(int x);
int min(int a, int b);
int max(int a, int b);

/* Standard I/O Functions */
int printf(const char *format, ...);
int scanf(const char *format, ...);
int puts(const char *str);
int getchar(void);
int putchar(int c);

/* Utility Functions */
void exit(int status);
int atoi(const char *str);
char *itoa(int value, char *str, int base);

#endif /* MLIB_H */
