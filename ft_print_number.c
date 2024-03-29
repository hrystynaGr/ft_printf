#include	"ft_printf.h"

int	ft_putnbr(int x)
{
	int	digits;

	digits = 0;
	if (x == -2147483648)
	{
		ft_print_char('-');
		ft_print_char('2');
		x = 147483648;
		digits += 2;
	}
	else if (x < 0)
	{
		ft_print_char('-');
		x = -x;
		digits++;
	}
	if (x >= 10)
	{
		digits += ft_putnbr(x / 10);
	}
	ft_print_char(x % 10 + '0');
	digits++;
	return (digits);
}
