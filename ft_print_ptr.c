#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int	counter;

	counter = 0;
	if (ptr == 0)
	{
		counter += write(1, "0x", 2);
		counter += write(1, "0", 1);
		//Linux solution
		/*write (1, "(nil)", 5);
		counter += 5;*/
	}
	else
	{
		counter += ft_print_str("0x");
		counter += ft_print_hexa((unsigned long)ptr, 'x');
	}
	return (counter);
}