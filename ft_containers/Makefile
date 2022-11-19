
#SRC	= ft_stack.cpp
#NAME	= stack

SRC		= ft_vector.cpp
NAME	= vector

#SRC	= ft_map.cpp
#NAME	= map

#SRC	= ft_set.cpp
#NAME	= set

HEADERS	= iterator_traits.hpp map.hpp reverse_iterator.hpp set.hpp stack.hpp tree.hpp utility.hpp vector.hpp

CC			= clang++

FLAGS		= 	-Wall -Wextra -Werror -std=c++98

OBJS		=   $(SRC:.cpp=.o)

RM 			= 	rm -f

.PHONY 	:	all clean flean re

$(NAME) : $(OBJS) $(HEADERS)
			@$(CC) $(OBJS) -o $(NAME)

all 	: 	$(NAME)

%.o		:	%.cpp
			$(CC) $(FLAGS) -c -o $@ $<

clean 	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re:		fclean all

