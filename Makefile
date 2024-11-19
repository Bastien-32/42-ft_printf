LIBC = ft_printf.c \
	ft_putnbr_addr_ptr.c ft_address.c ft_putnbr_base.c ft_strlen.c\
	ft_putchar.c ft_putnbr_pos.c ft_putnbr.c \

SRC = ${LIBC}

OBJS = ${SRC:.c=.o}


NAME = libftprintf.a 

CC = gcc

FLAGS = -Wall -Werror -Wextra

%.o: %.c
		${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
		ar -rsc ${NAME} ${OBJS}

all: ${NAME}

clean:
		rm -f ${OBJS}

fclean: clean;
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re