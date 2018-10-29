# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 15:37:25 by gdelabro          #+#    #+#              #
#    Updated: 2018/10/26 17:34:54 by gdelabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_SRC = ft_bzero.c ft_strcmp.c ft_strstr.c ft_memset.c ft_strlen.c ft_strcat.c ft_taille_nb.c

LIBFT_OBJ = $(addprefix libft/,$(LIBFT_SRC:.c=.o))

SRC_PATH = src
SRC_NAME = ft_printf.c format_remp.c conv_d.c conv_int.c conv_s.c conv_long_int.c conv_ls.c\
unicode.c conv_size_t.c conv_char.c conv_short_int.c change_conv.c conv_x.c conv_o.c conv_b.c colors.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

CPPFLAGS = -I includes -I libft/includes

LDFLAGS = -L libft
LDLIBS = -lft
LIB = libft/libft.a

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\n"
	@make -C libft
	@ar rc $@ $(OBJ) $(LIBFT_OBJ)
	@ranlib $(NAME)
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;5;32mOK\033[0;1m]"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "\033[33;1m$(NAME)\033[0;1m: objects deleted"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "\033[33;1m$(NAME)\033[0;1m: $(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re
