NAME := Fire
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJS := $(SRCS:.cpp=.o)
HEADS := AAnimal.hpp Cat.hpp Dog.hpp 

.PHONY : all clean fclean re run push debug

.SECONDARY : $(OBJS)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

run : re clean
	./$(NAME) $(ARGS)

debug : re
	valgrind ./$(NAME) $(ARGS)

push : fclean
	git add ../../.
	git commit -m "$(ARGS)"
	git push #class
