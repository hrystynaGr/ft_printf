NAME =  libftprintf.a
LIBFT_PATH	= ./libft --no-print-directory
LIBFT_NAME	= ./libft/libft.a
FILE = libftprintf.c


FLAGS	= -Wall -Wextra -Werror 
CC		= cc
RM		= rm -f
SRC	= ft_printf.c
OBJS = ${SRC:.c=.o}


all:	$(LIBFT_NAME) ${NAME} 

$(NAME):	${OBJS}
		${CC} ${FLAGS} $(FILE) ${OBJS} ${LIBFT_NAME} -o ttt

$(LIBFT_NAME):
		@make -C $(LIBFT_PATH)

clean:
		${RM} ${OBJS} 

fclean: clean
		${RM} $(LIBFT_NAME)

re:		fclean all

.PHONY:	all bonus clean fclean re