#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _putchar - Custom implementation of putchar to print a single character
 * @c: The character to be printed
 * Return: On success, return the number of characters written.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf - Custom implementation of printf function
 * @format: The format string containing directives
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
					break;
				case 's':
					{
						char *str = va_arg(args, char *);
						if (str == NULL)
							str = "(null)";
						while (*str)
						{
							printed_chars += _putchar(*str);
							str++;
						}
						break;
					}
				case '%':
					printed_chars += _putchar('%');
					break;
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(*format);
					break;
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}

		format++;
	}

	va_end(args);
	return (printed_chars);
}
