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
	  prep_exec.c\
	  toolbox3.c\
	  toolbox_hd.c\
	  valid_check.c\
	  varz.c\
	  built_in.c\
	  signal.c

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
		@clang $(OBJ) libft/libft.a -lreadline -o $(NAME) | echo "$(GREEN)OBJ compiled"

clean:
		@rm -f $(OBJ) | echo "$(YELLOW)clean OBJ"
		@make clean -C libft -s && echo "$(YELLOW)libft cleaned"

fclean: clean
		@rm -f $(NAME) | echo "$(RED)clean All"  
		@make fclean -C libft -s && echo "$(RED)libft cleaned"

re: fclean all

.PHONY : all clean fclean re
