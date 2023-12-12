#include "shell.h"
int myprintf(char *str, size_t size, const char *format, ...)
{
	int written, n;
	va_list args;

	if (str == NULL || format == NULL)
		return (-1);

	va_start(args, format);

	written = 0;
	n = size - 1;

	while (*format && n > 0)
	{
		if (*format == '%' && *(format + 1) == 's')
		{
			const char *s = va_arg(args, const char *);

			while (*s && n > 0)
			{
				*str++ = *s++;
				n--;
				written++;
			}
			format +=2;
		}
		else
		{
			*str++ = *format++;
			n--;
			written++;
		}
	}
	va_end(args);
	*str = '\0';

	return (written);
}
