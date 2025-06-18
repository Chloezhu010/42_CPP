# executable name
NAME = identify_real_type

# compiler & flags
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98


# src files
SRC = main.cpp \
		Base.cpp \
		Derived.cpp

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