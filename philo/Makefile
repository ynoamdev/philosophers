# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynoam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 15:15:17 by ynoam             #+#    #+#              #
#    Updated: 2021/07/12 15:16:39 by ynoam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c philo2.c philo3.c

CC = gcc -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -o $(NAME) $(SRC)

clean:
	@echo "no object files"

fclean: clean
	rm -f $(NAME)

re : fclean all
