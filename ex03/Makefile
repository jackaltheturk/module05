NAME = InternCases
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
SRCS = main.cpp Bureaucrat.cpp AForm.cpp \
	 ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
	 Intern.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re