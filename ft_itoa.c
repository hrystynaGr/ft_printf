/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkubik <kkubik@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:04:10 by kkubik            #+#    #+#             */
/*   Updated: 2023/01/19 19:10:59 by kkubik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itoa(int x)
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