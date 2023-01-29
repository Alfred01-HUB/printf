#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 *
 * @format: character string.
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list p;

	va_start(p, format);
	while (*format != '\0')
	{
		_putchar(*format);
		format++;
		i++;
	}	
		return (i);
}
