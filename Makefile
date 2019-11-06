##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC = main.c draw.c duck.c score_ammo.c doge.c struct.c intro.c useful_function.c duck_fly.c texture.c number.c

NAME = my_hunter

INCLUDES = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -I./include $(INCLUDES)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all