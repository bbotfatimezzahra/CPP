NAME := megaphone
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := megaphone.cpp
OBJS := $(SRCS:%.c=%.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) -o $(NAME) $(SRCS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
