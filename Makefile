NAME	:= fillit 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra ft_tetrread.c ft_mapsolve.c ft_utils.c main.c libft/*.c -c -I . -I libft/
	@gcc -Wall -Werror -Wextra *.o -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re:	fclean	all