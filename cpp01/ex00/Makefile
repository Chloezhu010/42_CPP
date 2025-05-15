# executable name
NAME = Zombie

# compiler & flags
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98


# src files
SRC = Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \
		main.cpp

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