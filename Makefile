# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 16:32:31 by ntom              #+#    #+#              #
#    Updated: 2019/09/04 02:04:35 by ntom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS += -Wall -Wextra -I includes
LIBDIR = srcs/libft

SRC = builtins.c ft_cd.c ft_echo.c ft_env.c ft_setenv.c ft_unsetenv.c \
		init_vars.c main.c signals.c tools.c free_stuff.c

O_FILES = $(SRC:%.c=%.o)
FLAGLIB = -L$(LIBDIR) -lft

all: $(NAME)

$(NAME): $(O_FILES)
	make all -C $(LIBDIR)
	@gcc $(CFLAGS) $(FLAGLIB) -o $(NAME) $(O_FILES)

clean:
	/bin/rm -rf $(O_FILES)
	make clean -C $(LIBDIR)

fclean: clean
	/bin/rm -rf $(NAME)
	make fclean -C $(LIBDIR)

lib:
	make re -C $(LIBDIR)

norm:
	@norminette $(SRC) | lolcat

normlib:
	@norminette $(LIBDIR)/*.c | lolcat

re: fclean all

.PHONY: all fclean clean re
