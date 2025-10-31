NAME = 	Fixed
CC = c++
CFLAG = -Wall -Wextra -Wall -std=c++98
RM = rm -rf
SRC = main.cpp Fixed.cpp
OPJ = $(SRC:.cpp=.o)
$(NAME): $(OPJ)
	$(CC) $(CFLAG) $(OPJ) -o $(NAME)
clean:
	$(RM) $(OPJ)
fclean: clean
	$(RM) $(NAME)
re: fclean $(NAME)