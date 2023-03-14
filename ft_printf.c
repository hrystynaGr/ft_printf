#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include "stdarg.h"

int ft_printf(const char *, ...);

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		put_ptr(num / 16);
		put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	print_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		put_ptr(ptr);
		print_length += ptr_len(ptr);
	}
	return (print_length);
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

int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print_length += ft_printstr(num);
		free(num);
	}
	return (print_length);
}

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}

void print_format(const char *c, va_list p)
{
    if (*c == 'd' || *c == 'i')
        ft_printstr(ft_itoa(va_arg(p, int)));
    else if (*c == 'c')
        ft_printchar(va_arg(p, int));
    else if (*c == 's')
        ft_printstr(va_arg(p, char*));
    else if (*c == 'p')
        print_ptr(va_arg(p, unsigned long int));
    else if (*c == 'u')
        ft_print_unsigned(va_arg(p, unsigned long int));
    else if (*c == 'x')
        ft_print_hex(va_arg(p, unsigned long int), 'x');
    else if (*c == 'X')
        ft_print_hex(va_arg(p, unsigned long int), 'X');
    else if (*c == '%')
		ft_printchar('%');
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