NAME := MoarBrainz
CC := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := $(wildcard *.cpp)
HEADS := $(wildcard *.hpp)

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
