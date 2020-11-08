CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = translate.a
OPTIONS = -L../opengl -lmlx -framework OpenGL -framework AppKit
SOURCES =	cal_and_init.c\
			color.c \
			dda.c \
			deal_key.c \
			main_hook.c \
			main.c \
			map.c \
			ver_line.c
all: $(NAME)

$(NAME):
		$(CC) $(OPTIONS) $(SOURCES) -o $(NAME)

fclean: clean
		$(RM) $(NAME)
re: fclean all

.PHONY: clean fclean all re
