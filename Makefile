NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -g -fsanitize=address
MLXFLAGS = -L ./minilibx -lmlx -framework OpenGl -framework Appkit
LIBFT = ./libft/libft.a
LIBFTDIR = ./libft
MINILIBX_PATH = ./minilibx
MINILIBX = ./minilibx/libmlx.a
SRC = source_files/init_map_sprite.c \
	  source_files/init_map1.c \
	  source_files/init_window.c \
	  source_files/map_check1.c \
	  source_files/so_long.c \
	  source_files/utils.c \
	  source_files/free_error.c

OBJ = $(SRC:.c=.o)

all: ${NAME}

${NAME}: $(OBJ)
		$(MAKE) --no-print-directory -C $(MINILIBX_PATH)
		@echo "Minilibx compilation success!"
		$(MAKE) -C $(LIBFTDIR)
		$(CC) $(CFLAGS) -lm $(SRC) $(MLXFLAGS) $(LIBFT) -o $(NAME)
		@echo "./so_long created!"

clean:
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./minilibx
		@rm -rf $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		@rm -rf $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re