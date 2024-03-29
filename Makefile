SRCS =	ft_printf.c ft_print_char.c\
		ft_print_str.c ft_print_ptr.c ft_print_hexa.c\
		ft_print_unsign_number.c ft_print_number.c ft_itoa.c
		
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
INCS = ft_printf.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}
		
${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
