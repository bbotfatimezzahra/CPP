NAME := Trap
CC := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
HEADS := ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

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
	git push #class
