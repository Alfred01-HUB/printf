#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 *
 * @format: character string.
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i = 0, x;
	char c, *s;
	va_list p;

	if (format == 0)
		return (-1);
	va_start(p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{	format++;
			if (*format == 0)
				return (-1);
			else if (*format == '%')
				_putchar(*format);
			else if (*format == 'd' || *format == 'i')
			{
				x = va_arg(p, int);
				s = (char *) malloc(INT_MAX);
				if (s == NULL)
					return (0);
				sprintf(s, "%d", x);
				while (*s != '\0')
				{
					i++;
					_putchar(*s++);
				} i--;
			} else if (*format == 'c')
			{
				c = va_arg(p, int);
				_putchar(c);
			} else if (*format == 's')
			{
				s = va_arg(p, char *);
				while (*s != '\0')
				{
					i++;
					_putchar(*s++);
				} i--;
			}
			else
				_putchar(*--format);
			format++;
			i++;
			continue;
		}
		_putchar(*format++);
		i++;
}
		return (i);
}
