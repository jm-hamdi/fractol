# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jm-hamdi <jm-hamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 20:03:22 by jm-hamdi          #+#    #+#              #
#    Updated: 2022/08/03 21:18:29 by jm-hamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror 

NAME=fractol

SRCS=	main.c utils.c utils1.c \
		mandelbrot.c julia.c \

INC = fractol.h

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS) $(HD)
		CC $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit $(OBJCTS) -o $(NAME)

all : $(NAME)

clean:
		rm -f $(OBJCTS) $(BOBJCTS)

fclean: clean
		rm -f $(NAME)

re : fclean all