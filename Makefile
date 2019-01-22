# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 12:56:38 by wqarro-v          #+#    #+#              #
#    Updated: 2019/01/21 17:27:17 by wqarro-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

MAIN = main.c

SRC = validation.c error.c map.c solution.c

LIB = ./libft/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	@$(MAKE) -C $(LIB)
	gcc $(FLAGS) -o $(NAME) $(MAIN) $(SRC) ./libft/libft.a -I $(LIB)

clean:
	@$(MAKE) -C $(LIB) clean

fclean: clean
	@$(MAKE) -C $(LIB) fclean
	rm -f $(NAME)

re: fclean all
