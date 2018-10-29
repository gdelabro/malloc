# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 12:46:39 by gdelabro          #+#    #+#              #
#    Updated: 2018/10/26 17:32:43 by gdelabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FC = ft_bzero.c ft_strcmp.c ft_strstr.c ft_memset.c ft_strlen.c ft_strcat.c ft_taille_nb.c

OBJ = $(FC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "libft: [\033[32;1mOK\033[0;1m]\n"

%.o: %.c
	@printf "\033[35;1m| \033[0;1m"
	@gcc -Wall -Wextra -Werror -c $<

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf libft.a

re : fclean all
