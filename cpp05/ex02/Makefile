# executable name
NAME = ex02

# compiler & flags
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98


# src files
SRC_DIR = src
SRC = main.cpp \
		$(SRC_DIR)/Bureaucrat.cpp \
		$(SRC_DIR)/Form.cpp \
		$(SRC_DIR)/ShrubberyCreationForm.cpp \
		$(SRC_DIR)/RobotomyRequestForm.cpp \
		$(SRC_DIR)/PresidentialPardonForm.cpp

# obj files
OBJ = $(SRC:.cpp=.o)


# rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re