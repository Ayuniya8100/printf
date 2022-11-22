#include "main.h"
/**
  * check_for_specifiers - checks if there is a valid format specifier
  * @format: possible format specifier
  *Return: pointer to valid function or NULL
  */
static int (*check_for_specifiers(const char *format))(va_list)
{
	unsigned int i;

	func_t ptr[] = {
		{"c", print_c},
		{"s", print_s},
		{NULL, NULL}
	};

	for (i = 0; ptr[i].t != NULL; i++)
	{
		if (*(ptr[i].t) == *format)
			break;
	}
	return (ptr[i].f);
}

/**
  * _printf - to print  anything
  * @format: list of argument types passed to the function
  *
  * Return: number of characters printed
  */

int _printf(const char *format, ...)
{
	unsigned int i, count = 0;
	va_list args;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		for (i = 0; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
	if (!format[i])
		return (count);
	f = check_for_specifiers(&format[i + 1]);
	if (f != NULL)
	{
		count += f(args);
		i += 2;
		continue;
	}
	if (!format[i + 1])
		return (-1);
	_putchar(format[i]);
	count++;
	if (format[i + 1] == '%')
		i += 2;
	else
		i++;
	}
	va_end(args);
	return (count);
	}
