#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
int _printf(const char *format, ...);
typedef struct func
{
	char *t;
	int (*f)(va_list);
} func_t;
int print_c(va_list c);
int print_s(va_list s);
int _putchar(char c);
#endif
