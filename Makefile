SOURCE_FILES =	ft_main.c \
				ft_radix.c \
				ft_split.c \
				ft_moves.c \
				ft_push_swap.c \
				ft_functions.c \
				ft_hardcoded.c \
				ft_functions2.c \
				ft_hardcoded2.c \

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

OBJECTS = $(addprefix push_swap_objects/, $(SOURCE_FILES:.c=.o))

all: $(NAME)

push_swap_objects/%.o: %.c
	@mkdir -p push_swap_objects
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
