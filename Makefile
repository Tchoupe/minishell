# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 16:32:31 by ntom              #+#    #+#              #
#    Updated: 2019/06/09 16:44:52 by ntom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell.a

SRCS = ft_cd ft_env ft_unsetenv init_vars builtins ft_echo ft_setenv main tools

CC = gcc

CFLAGS += -Wall -Werror -Wextra

INCLUDES = ./includes/minishell.h

FILES = $(addprefix ./, $(SRCS))

CFILES = $(addsuffix .c, $(FILES))

OFILES = $(addsuffix .o, $(FILES))

OBJS = $(CFILES:.c=.o)

LIB_PATH = ./srcs/libft/

LIB = $(addsuffix libft.a, $(LIB_PATH))

all: $(NAME)

$(NAME): $(OBJS)
#	@make -C $(LIB_PATH)
	@echo compiling executable..
	@ar rc $(NAME) $(OFILES)
	@libtool -static -o $(NAME) $(NAME) $(LIB)
	@echo done

clean:
#	make clean -C $(LIB_PATH)
	echo cleaning local files.o
	rm -f $(OFILES)
	echo done.

fclean: clean
	make fclean -C $(LIB_PATH)
	echo cleaning executable
	rm -f $(NAME)
	echo done.

re: fclean all

.PHONY: all clean fclean re
.SILENT: clean fclean re $(OBJS)
