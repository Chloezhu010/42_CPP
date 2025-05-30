# executable name
NAME = ClapTrap_ex03

# compiler & flags
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98


# src files
SRC = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp

# obj files
OBJ = $(SRC:.cpp=.o)


# rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re