# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 09:35:10 by sslaoui           #+#    #+#              #
#    Updated: 2024/02/29 15:23:29 by sslaoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

Flags = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c

OBJ = ${SRCS:.c=.o}

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -cr $(NAME) $(OBJ)

%.o : %.c ft_printf.h
	$(CC) $(Flags) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean :
	@rm -f $(NAME)

re : fclean all