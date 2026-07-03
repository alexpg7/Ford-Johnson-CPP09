NAME = PmergeMe
SRC = main.cpp \
	PmergeMe.cpp \
	sorting.cpp

INCLUDE = Makefile PmergeMe.hpp

OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

# Colors
BRED = \033[1;31m
BYEL = \033[1;33m
BGREEN = \033[1;32m
RED = \033[0;31m
YEL = \033[0;33m
GREEN = \033[0;32m
NC = \033[0m

all : $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME)	: $(OBJ) $(INCLUDE)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "😃 ${BGREEN}Compiled ${BYEL}$(NAME)"

fclean: clean
	@$(RM) $(NAME)
	@echo "🗑️  $(BRED)Removed $(YEL)$(NAME)"

clean:
	@$(RM) $(OBJ)
	@echo "🗑️  $(BRED)Removed $(RED)$(OBJ)"

re: fclean all

.PHONY: all clean fclean re
