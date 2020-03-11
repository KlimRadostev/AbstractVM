#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kradoste <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 15:54:17 by kradoste          #+#    #+#              #
#    Updated: 2020/02/01 21:24:24 by kradoste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = abstractVM
CC = g++
FLAGS = -Wall -Wextra -Werror
SRC = *.cpp

$(NAME): $(SRC)
	@$(CC) $(FLAGS) -o $(NAME) $(SRC)

all: $(NAME)

clean:
	@/bin/rm -f *~
	@/bin/rm -f \#*\#

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
