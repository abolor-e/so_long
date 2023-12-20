NAME = so_long

LIBFT = ./libft/libft.a

# Don't forget to add gnl to libft!

SRCS =	so_long.c	\
		init_map.c	\
		map_check.c	\
		init_window.c	\
		init_map_sprite.c	\
		utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS =  -Wall -Werror -Wextra

CC		= cc

RM		= rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

${LIBFT}:
	${MAKE} -C ./libft

$(NAME): $(OBJECTS) ${LIBFT}
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	${MAKE} clean -C ./libft
	${RM} ${OBJS}

fclean: clean
	${MAKE} fclean -C ./libft
	${RM} $(NAME)

re: fclean $(NAME)