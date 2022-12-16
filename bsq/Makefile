# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minh-ngu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 10:56:09 by minh-ngu          #+#    #+#              #
#    Updated: 2022/10/05 19:32:12 by minh-ngu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES := ./srcs/ft_atoi.c ./srcs/ft_putnbr.c ./srcs/ft_read.c ./srcs/ft_str_is_printable.c ./srcs/ft_putchar.c  ./srcs/ft_putstr.c  ./srcs/ft_resolve.c  ./srcs/ft_strdup.c ./srcs/ft_read_v1.c ./srcs/main.c ./srcs/ft_map.c
OBJECTS := ${SOURCES:.c=.o}
CC	:= gcc
CFLAGS	:= -Wall -Wextra -Werror
NAME 	:= bsq

all: ${NAME}

%o: %c
	${CC} ${CFLAGS} -c $< -o $@ -I ./includes

${NAME}: ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -I ./includes -o ${NAME}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME} 

re: fclean all

.PHONY: all clean fclean re
