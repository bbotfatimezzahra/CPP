# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbbot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 19:06:02 by fbbot             #+#    #+#              #
#    Updated: 2025/06/01 19:08:04 by fbbot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Sed2.0
CC := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := main.cpp
#HEADS := 

.PHONY : all clean fclean re run push debug

all : $(NAME)

$(NAME) : $(SRCS) #$(HEADS)
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
