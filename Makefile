all: fillit tetrgen
fillit:
	@gcc -Wall -Werror -Wextra -o fillit  main.c ft_validate_tetr.c ../get_next_line/get_next_line.c -I . -I ../get_next_line/. ../libft/libft.a
tetrgen:
	@gcc -Wall -Werror -Wextra -o tetrgen ft_generate_tetr.c
fclean:
	@rm fillit
	@rm tetrgen
re: fclean all
