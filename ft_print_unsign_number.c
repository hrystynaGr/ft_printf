#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int x)
{
	int	digits;

	digits = 0;
	if (x >= 10)
	{
		digits += ft_putnbr_unsigned(x / 10);
	}
	ft_print_char(x % 10 + '0');
	digits++;
	return (digits);
}
