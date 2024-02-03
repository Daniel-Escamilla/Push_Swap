SOURCE_FILES =	ft_push_swap.c \
				ft_functions.c \
				ft_functions2.c \
				ft_split.c \
				ft_moves.c \
				ft_hardcoded.c \
				ft_hardcoded2.c \
				ft_main.c \

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

OBJECTS = $(SOURCE_FILES:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

git:
	git add .
	git status
	@read -p "¿Continuar? [y/n]: " answer; \
	if [ "$$answer" = "y" ]; then \
		read -p "Mensaje para el commit: " message; \
		git commit -m "$$message"; \
		git push; \
	fi

re: clean all

.PHONY: re fclean clean all
