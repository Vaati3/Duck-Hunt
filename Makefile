##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC = src/main.c src/draw.c src/duck.c src/score_ammo.c src/doge.c src/struct.c src/intro.c src/useful_function.c src/duck_fly.c src/texture.c src/number.c

NAME = duck_hunt

INCLUDES = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -I./include $(INCLUDES)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
