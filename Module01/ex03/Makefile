# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbbot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 19:03:11 by fbbot             #+#    #+#              #
#    Updated: 2025/06/01 19:04:05 by fbbot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Violent
CC := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
HEADS := Weapon.hpp HumanA.hpp HumanB.hpp

.PHONY : all clean fclean re run push debug

all : $(NAME)

$(NAME) : $(SRCS) $(HEADS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf $(NAME)

re : clean all

run : re
	./$(NAME) $(ARGS)

debug : re
	valgrind ./$(NAME) $(ARGS)

push : clean
	git add ../../.
	git commit -m "$(ARGS)"
	git push class
