#include "ft_printf.h"

int print_format(const char *c, va_list p, int counter)
{
    if (*c == 'd' || *c == 'i')
        counter+=ft_print_char(va_arg(p, int));
    else if (*c == 'c')
        counter+=ft_print_char(va_arg(p, int));
    else if (*c == 's')
        counter+=ft_print_str(va_arg(p, char*));
    else if (*c == 'p')
        counter+=ft_print_ptr(va_arg(p, void *));
    else if (*c == 'u')
        counter+=ft_putnbr_unsigned(va_arg(p, unsigned long int));
    else if (*c == 'X' || *c == 'x')
        counter+=ft_print_hexa(va_arg(p, unsigned int), *c);
    else if (*c == '%')
		counter+=ft_print_char('%');
    return (counter);
}

int ft_printf(const char *cond, ...)
{
    va_list params;
    va_start(params, cond);
    int i;
    int counter;

    i = 0;
    counter = 0;
    while (cond[i] != '\0')
    {
        if (cond[i] == '%')
        {
            counter = print_format(&cond[i + 1], params, counter);
            i+=2;
        }
        else
        {
            counter += ft_print_char(cond[i]);
            i++;
        }
    }
    return counter;
}
