# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 15:37:25 by gdelabro          #+#    #+#              #
#    Updated: 2018/11/12 19:25:42 by gdelabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

SRC_PATH = src
SRC_NAME = malloc.c free.c creat_block.c tiny_malloc.c init_global_var.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MFLAGS =  -shared -o
LDLIB = -L ft_printf -lftprintf
LIB = ft_printf/libftprintf.a
LIBTEST = libft_malloc.a

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(LIB) test#$(NAME)

$(LIB):
	@make -C ft_printf

$(NAME): $(OBJ)
	@printf "\n"
	@$(CC) $(MFLAGS) $(@) $(OBJ) $(LDLIB)
	@echo "Compilation of \033[32;1m$(NAME)\033[0;1m: [\033[1;5;32mOK\033[0;1m]"
	@rm -rf libft_malloc.so
	@ln -s $(NAME) libft_malloc.so
	@echo "Link of \033[32;1m$(NAME)\033[0;1m to \033[32;1mlibft_malloc.so\033[0;1m: [\033[1;5;32mOK\033[0;1m]"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@printf "\033[32;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

test: $(LIB) $(LIBTEST)

main.o: main.c
	@gcc -c $< -o $@
	@echo "\033[1mCompilation of file \033[32;12mmain.c\033[0;1m: [\033[1;5;32mOK\033[0;1m]"

$(LIBTEST): main.o $(OBJ)
	@ar rc $(LIBTEST) $(OBJ)
	@echo "Compilation of test lib \033[32;14mlibft_malloc.a\033[0;1m: [\033[1;5;32mOK\033[0;1m]"
	@gcc main.o $(LIB) $(LIBTEST)

clean:
	@make -C ft_printf clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	rm -rf main.o
	@echo "\033[32;1m$(NAME)\033[0;1m: objects deleted"

fclean: clean
	@make -C ft_printf fclean
	@rm -rf $(NAME)
	@rm -rf $(LIBTEST)
	@rm -rf libft_malloc.so
	@echo "\033[32;1m$(NAME)\033[0;1m: $(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re
