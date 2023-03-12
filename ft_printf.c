#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include "functions.h"
#include "stdarg.h"

int ft_printf(const char *, ...);

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char	*s)
{
	int	i;
	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		i++;
	return (write(1, s, i));
}

void print_format(const char *c, va_list p)
{
    if (*c == 'd' || *c == 'i')
        ft_printstr(ft_itoa(va_arg(p, int)));
    else if (*c == 'c')
        ft_printchar(va_arg(p, int));
    else if (*c == 's')
        ft_printstr(va_arg(p, char*));
}

int ft_printf(const char *cond, ...)
{
    va_list params;
    va_start(params, cond);
    int i;

    i = 0;
    while (cond[i] != '\0')
    {
        if (cond[i] == '%')
        {
            print_format(&cond[i + 1], params);
            i+=2;
        }
        else
        {
            ft_printchar(cond[i]);
            i++;
        }
    }
    return 0;
}