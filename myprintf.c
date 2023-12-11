#include "shell.h"

void myprintf(char *buffer, const char *format, const char *arg)
{
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) == 's')
		{
			while (*arg != '\0')
			{
				*buffer = *arg;
				buffer++;
				arg++;
			}
			format +=2;
		}
		else
		{
			*buffer = *format;
			buffer++;
			format++;
		}
	}
	*buffer = '\0';
}
