NAME				= so_long


CC					= cc
-------------------------------------------------------------------------
# Compiling flags!
CFLAGS				= -Wall -Werror -Wextra
MINILIBX_FLAGS		= -lmx -lXext -lX11

-------------------------------------------------------------------------
# Library
LIBFT				= libft/libft.a

-------------------------------------------------------------------------
REMOVE				= rm -rf

-------------------------------------------------------------------------
SRCS				= 


all:				${LIBFT} ${NAME}

${NAME}:			${CC} ${CFLAGS} ${MINILIBX_FLAGS} ${SRCS} ${LIBFT} -o ${NAME}

