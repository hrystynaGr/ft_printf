# NAME =  libftprintf.a
# LIBFT_PATH	= ./libft --no-print-directory
# LIBFT_NAME	= ./libft/libft.a
# FILE = libftprintf.c


# FLAGS	= -Wall -Wextra -Werror 
# CC		= cc
# RM		= rm -f
# SRC	= ft_printf.c
# OBJS = ${SRC:.c=.o}


# all:	$(LIBFT_NAME) ${NAME} 

# $(NAME):	${OBJS}
# 		${CC} ${FLAGS} $(FILE) ${OBJS} ${LIBFT_NAME}
# 		@ar -r $(NAME) $(OBJS)

# $(LIBFT_NAME):
# 		@make -C $(LIBFT_PATH)

# clean:
# 		${RM} ${OBJS} 

# fclean: clean
# 		${RM} $(LIBFT_NAME)

# re:		fclean all

# .PHONY:	all bonus clean fclean re

NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SRCS = 	ft_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all
