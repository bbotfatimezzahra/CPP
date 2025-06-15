NAME := Intern
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
SRCS :=  main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS := $(SRCS:.cpp=.o)
HEADS := $(SRCS:.cpp=.hpp)

.PHONY : all clean fclean re run push debug

.SECONDARY : $(OBJS)

all : $(NAME)

$(NAME) : $(OBJS) #$(HEADS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

run : re 
	rm -rf $(OBJS)
	./$(NAME) $(ARGS)

debug : re
	valgrind --leak-check=full ./$(NAME) $(ARGS)

push : fclean
	git add ../../.
	git commit -m "$(ARGS)"
	git push #class
