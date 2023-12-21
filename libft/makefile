# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 13:51:08 by abolor-e          #+#    #+#              #
#    Updated: 2023/12/21 14:26:15 by abolor-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

SRCS		= ft_isalpha.c	\
			  ft_isdigit.c	\
			  ft_isalnum.c	\
			  ft_isascii.c	\
			  ft_isprint.c	\
			  ft_strlen.c	\
			  ft_memset.c	\
			  ft_bzero.c	\
			  ft_memcpy.c	\
			  ft_memmove.c	\
			  ft_strlcpy.c	\
			  ft_strlcat.c	\
			  ft_calloc.c	\
			  ft_strdup.c	\
			  ft_toupper.c	\
			  ft_tolower.c	\
			  ft_strchr.c	\
			  ft_strrchr.c	\
			  ft_strncmp.c	\
			  ft_memchr.c	\
			  ft_memcmp.c	\
			  ft_strnstr.c	\
			  ft_atoi.c	\
			  ft_substr.c	\
			  ft_strjoin.c	\
			  ft_strtrim.c	\
			  ft_split.c	\
			  ft_itoa.c	\
			  ft_strmapi.c	\
			  ft_striteri.c	\
			  ft_putchar_fd.c	\
			  ft_putstr_fd.c	\
			  ft_putendl_fd.c	\
			  ft_putnbr_fd.c	\
			  get_next_line.c \
			  ft_lowhexa.c \
			  ft_nputchar.c \
			  ft_nputnbr.c \
			  ft_nputstr.c \
			  ft_pputnbr.c \
			  ft_printf.c \
			  ft_putaddr.c \
			  ft_upphexa.c 
			  
			  

SRCS_BONUS	= ft_lstnew.c	\
			  ft_lstadd_front.c	\
			  ft_lstsize.c	\
			  ft_lstlast.c	\
			  ft_lstadd_back.c	\
			  ft_lstdelone.c	\
			  ft_lstclear.c	\
			  ft_lstiter.c	\
			  ft_lstmap.c

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
				ar -rcs ${NAME} ${OBJS}

%.o:		%.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus:		${OBJS} ${OBJS_BONUS}
				ar -rcs ${NAME} ${OBJS} ${OBJS_BONUS}

clean:
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
				${RM} ${NAME} ${bonus}

re:			fclean all

.PHONY:		all clean fclean re bonus
