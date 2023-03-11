#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include "functions.h"
#include "stdarg.h"

int ft_printf(const char *, ...);

// void print_d()
// {
//     int n = va_arg(params, int);
// }
int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

// int	ft_printchar(char *c)
// {
// 	write(1, c, 1);
// 	return (1);
// }
// void	ft_print_str(char *str)
// {
// 	int	i;
//     write(1, "ft_print_str", 13);
// 	i = 0;
// 	if (str == NULL)
// 	{
//         write(1, "str is null", 12);
// 		ft_print_str("(null)");
// 		return (1);
// 	}
// 	while (str[i])
// 	{
//         write(1, "l", 1);
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// 	return (i);
// }

void print_format(const char *c, va_list p)
{
    if (*c == 'd')
    {
        write(1, "dd", 3);
        // ft_printchar(va_arg(p, int));
    }
        
        // write(1, va_arg(p, int), 1);
    else if (*c == 'c'){
        ft_printchar(va_arg(p, int));
        // write(1, "Hi", 3);
        // printf("%d", va_arg(p, char *));
        // write(1, va_arg(p, char *), 1);
    }      
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
    // int paramsNum = 6;
    // if (*cond == 'c')
    // {
    //     while(paramsNum != 0)
    //     {
    //         char param = va_arg(params, char);
    //         printf("Char input: %c\n", param);
    //         paramsNum--;
    //     }

    // }
    // else
    // {
    //     while(paramsNum != 0)
    //     {
    //         int n = va_arg(params, int);
    //         printf("Int input: %d\n", n);
    //         paramsNum--;
    //     }
    // }
    // write(1, "f", 2);
    return 0;
}