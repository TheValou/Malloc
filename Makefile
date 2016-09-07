NAME	= libmy_malloc_$(HOSTTYPE).so

SYM	= libmy_malloc.so

SRC	= libmy_malloc.c

RM	= rm -f

CC	= gcc

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -W -Werror -fPIC

LDFLAGS = -shared

all:	$(NAME) $(SYM)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

$(SYM):
	ln -s $(NAME) $(SYM)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(SYM)

re: fclean all

.PHONY: all clean fclean re
