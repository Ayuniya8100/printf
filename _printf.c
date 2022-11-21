#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * _vfprintf - implement printf by using variadic function
 * @format: the first argument
 * Return: return length
 */
int _printf(const char *format, ...);
int _fprintf(FILE *file, const char *format, ...);

int _vfprintf(FILE *file, const char *format, va_list args)
{
	char char_temp;
	char *string_temp;
	char ch;
	int length = 0;

	while (ch = *format++)
	{
		if (ch == '%')
		{
			switch (ch = *format++)
			{
				case '%':
					fputc('%', file);
					length++;
					break;
				case 'c':
					char_temp = va_arg(args, int);
					fputc(char_temp, file);
					length++;
					break;
				case 's':
					string_temp = va_arg(args, char *);
					fputs(string_temp, file);
					length += strlen(string_temp);
					break;
			}
		}
		else
		{
			fputc(ch, file);
			length++;
		}
	}
	return (length);
}
/**
 *_printf - print format specifier
 * @format: string ointer
 * Return: return length
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int length = _vfprintf(stdout, format, args);

	va_end(args);
	return (length);
}
/**
 * _fprintf - function definition for file handiling
 * @file: string pointer
 * @format: string pointer
 * Return: return length
 */
int _fprintf(FILE *file, const char *format, ...)
{
	va_list args;
	int length;

	va_start(args, format);
	length = _vfprintf(file, format, args);
	va_end(args);
	return (length);
}
