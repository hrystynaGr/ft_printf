#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h> 
# include <stdio.h>

int		ft_printf(const char *string, ...);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(void *ptr);
int		ft_print_hexa(unsigned long num, char type);
int		ft_putnbr(int x);
int		ft_putnbr_unsigned(unsigned int x);
int	  ft_itoa(int n);

#endif