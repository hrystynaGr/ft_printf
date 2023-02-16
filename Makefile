NAME =  libftprintf.a
LIBFT_PATH	= ./libft --no-print-directory
LIBFT_NAME	= ./libft/libft.a


FLAGS	= -Wall -Wextra -Werror 
CC		= cc
RM		= rm -f
SRC	= ft_printf.c
OBJS = ${SRC:.c=.o}


all:	$(LIBFT_NAME) ${NAME} 

$(NAME):	${OBJS}
		${CC} ${FLAGS} -o $(NAME) ${OBJS}

$(LIBFT_NAME):
		@make -C $(LIBFT_PATH)

clean:
		${RM} ${OBJS} 

fclean: clean
		${RM} ${NAME} $(LIBFT_NAME)

re:		fclean all