# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 16:32:31 by ntom              #+#    #+#              #
#    Updated: 2019/06/09 16:56:38 by ntom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
F = -Wall -Wextra -Werror
S = builtins.c ft_env.c ft_cd.c ft_setenv.c init_vars.c ft_echo.c ft_unsetenv.c main.c tools.c
O = builtins.o ft_env.o ft_cd.o ft_setenv.o init_vars.o ft_echo.o ft_unsetenv.o main.o tools.o
NAME = libft.a

all: $(NAME)

$(NAME):
	   @$(C) $(F) -I. -c $(S) ./srcs/libft/libft.a
	   @ar rc $(NAME) $(O)
	   @ranlib $(NAME)

clean:
	   @rm -f $(O)

fclean: clean
	   @rm -f $(NAME)

re: fclean $(NAME)
