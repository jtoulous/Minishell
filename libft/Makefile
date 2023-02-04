NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_strjoin.c ft_strtrim.c ft_substr.c freedom.c extra.c ft_atof.c close.c get_next_line.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c #get_next_line_utils.c

#SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

CFLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(SRC:.c=.o) $(SRC_BONUS:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:$(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS)

.PHONY:
	all clean fclean re bonus
