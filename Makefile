NAME		= fillit
LIB_DIR		= libft/
LIB_LINK	= -L $(LIB_DIR) -l ft
SRCS		= ft_tetrread.c ft_mapsolve.c ft_utils.c 
SRCS_OBJS	= $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR) --no-print-directory
	@gcc -Wall -Werror -Wextra -c $(SRCS) -I . -I $(LIB_DIR)
	@gcc -o $(NAME) $(SRCS_OBJS) $(LIB_LINK)

clean:
	@rm -rf $(SRCS_OBJS)
	@make -C $(LIB_DIR) clean --no-print-directory

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIB_DIR) fclean --no-print-directory	

re:	fclean	all
