NAME =  minishell

SRC = error_management.c\
	  errorz.c\
	  exec.c\
	  extract.c\
	  inredir.c\
	  heredoc.c\
	  minishiat.c\
	  outredir.c\
	  parse.c\
	  toolbox.c\
	  toolbox2.c\
	  trimage.c\
	  built_in.c\

CFLAGS = -Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

# Colors
RED=\033[38;5;9m
GREEN=\033[38;5;76m
YELLOW=\033[38;5;11m

%.o: %.c
	@clang $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft -s && echo "$(GREEN)libft compiled"
		@make -C ft_printf -s && echo "$(GREEN) ft_printf compiled"
		@clang $(OBJ) libft/libft.a ft_printf/libftprintf.a  -lreadline -o $(NAME) | echo "$(GREEN)OBJ compiled"

clean:
		@rm -f $(OBJ) | echo "$(YELLOW)clean OBJ"
		@make clean -C libft -s && echo "$(YELLOW)libft cleaned"
		@make clean -C ft_printf -s && echo "$(YELLOW)ft_printf cleaned"

fclean: clean
		@rm -f $(NAME) | echo "$(RED)clean All"  
		@make fclean -C libft -s && echo "$(RED)libft cleaned"
		@make fclean -C ft_printf -s && echo "$(RED)ft_printf cleaned"

re: fclean all

.PHONY : all clean fclean re
