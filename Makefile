SOURCE_FILES =	src/ft_main.c \
				src/ft_radix.c \
				src/ft_split.c \
				src/ft_moves.c \
				src/ft_push_swap.c \
				src/ft_functions.c \
				src/ft_hardcoded.c \
				src/ft_functions2.c \
				src/ft_hardcoded2.c \

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

OBJECTS = $(addprefix push_swap_objects/, $(SOURCE_FILES:.c=.o))

all: $(NAME)

push_swap_objects/%.o: %.c
	@mkdir -p push_swap_objects/src
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(CC) $(CFLAGS) $<

$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	@rm -rf push_swap_objects

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
