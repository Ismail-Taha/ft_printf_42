SRCS		= ft_printf.c \
			  utils.c \
			  ft_printchar.c \
			  ft_printstr.c \
			  ft_printpointer.c \
			  ft_printnum.c \
			  ft_printunum.c \
			  ft_printbnum.c
OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
CC			= gcc -Wall -Wextra -Werror

%.o: %.c ft_printf.h
			${CC} -I. -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS} ft_printf.h
			ar rcs ${NAME} ${OBJS}

bonus:		${OBJS} ft_printf.h
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
