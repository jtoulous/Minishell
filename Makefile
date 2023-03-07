NAME =  minishell

SRC = error_management.c\
	  checks.c\
	  exec.c\
	  extract.c\
	  redir.c\
	  heredoc.c\
	  minishiat.c\
	  parse.c\
	  toolbox.c\
	  toolbox2.c\
	  toolbox3.c\
	  toolbox4.c\
	  toolbox_hd.c\
	  toolbox_export.c\
	  trimage.c\
	  prep_exec.c\
	  valid_check.c\
	  varz.c\
	  built_in.c\
	  echo.c\
	  export.c\
	  path.c\
	  exit.c\
	  signal.c\
	  global.c\

CFLAGS = -Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

# Colors
RED=\033[38;5;9m
GREEN=\033[38;5;76m
YELLOW=\033[38;5;11m
RESET=\033[00m

FLAG1 =	@printf "\n$(RED)░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAG2 =	printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAG3 =	printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAG4 =	printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAG5 =	printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAG6 =	printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAG7 =	printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████▓▓████▓▓▓▓██▓▓████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAG8 = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓▓▓████████▓▓██▓▓▓▓▓▓██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAG9 = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██▓▓▓▓██████▓▓▓▓▓▓██▓▓▓▓██████░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGA = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░████████          ▓▓██▓▓████▓▓████░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGB = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░██████                ████▓▓████▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGC = printf "░░░░░░░░░░░░░░░░░░░░░░░░░██▓▓██        ████▓▓███▓▓██▓▓█▓▓▓▓███▓██░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGD = printf "░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓        ▓▓████▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓█▓▓██▓░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGE = printf "░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓      ██████████████▓▓      ▓█████▓▓░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGF = printf "░░░░░░░░░░░░░░░░░░░░░░░░░▓▓██      ██████████████          ██▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGG = printf "░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓      ██▓▓██▓▓▓▓▓▓▓▓▓▓      ████▓▓█▓░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGH = printf "░░░░░░░░░░░░░░░░░░░░░░░░░▓▓██        ████████▓██▓▓█  █▓  ██▓▓▓█▓▓░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGI = printf "░░░░░░░░░░░░░░░░░░░░░░░░░██████        ████████████████▓▓████████░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGJ = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓████                ▓▓▓▓██▓▓████▓▓░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGK = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓████▓▓           ▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGL = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██▓▓▓██▓██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓████░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGM = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓██▓▓████░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGN = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓██▓▓██████████▓▓████▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGO = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓████████████▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGP = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGQ = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGR = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGS = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
FLAGT = printf "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░$(RESET)\n"

TURKEY = $(FLAG1);$(FLAG2);$(FLAG3);$(FLAG4);$(FLAG5);$(FLAG6);$(FLAG7);$(FLAG8);$(FLAG9);$(FLAGA);$(FLAGB);$(FLAGC);$(FLAGD);$(FLAGE);$(FLAGF);$(FLAGG);$(FLAGH);$(FLAGI);$(FLAGJ);$(FLAGK);$(FLAGL);$(FLAGM);$(FLAGN);$(FLAGO);$(FLAGP);$(FLAGQ);$(FLAGR);$(FLAGS);$(FLAGT)

%.o: %.c
	@clang $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft -s && echo "$(GREEN)libft compiled"
		@clang $(OBJ) libft/libft.a -lreadline -o $(NAME) | echo "$(GREEN)OBJ compiled"
		$(TURKEY)

clean:
		@rm -f $(OBJ) | echo "$(YELLOW)clean OBJ"
		@make clean -C libft -s && echo "$(YELLOW)libft cleaned"

fclean: clean
		@rm -f $(NAME) | echo "$(RED)clean All"  
		@make fclean -C libft -s && echo "$(RED)libft cleaned"

re: fclean all

.PHONY : all clean fclean re
