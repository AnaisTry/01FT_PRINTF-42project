# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angassin <angassin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 17:09:20 by angassin          #+#    #+#              #
#    Updated: 2022/07/07 17:20:16 by angassin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_isalpha.c ft_isdigit.c  ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c  ft_putnbr_fd.c \
			ft_nbrlen_base.c ft_putnbr_base_fd.c ft_put_unbr_base_fd.c \
			ft_unbrlen_base.c \
		  
BONUS_SRCS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c
				
OBJS 	=	${SRCS:.c=.o}

OBJSBONUS	= ${BONUS_SRCS:.c=.o}

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -g 

.c.o: 
				${CC} ${CFLAGS} -c $< -o  ${<:.c=.o}

${NAME}:	${OBJS}
				ar -rcs  ${NAME} ${OBJS}

bonus:		${OBJS} ${OBJSBONUS}
				ar -rcs ${NAME} ${OBJS} ${OBJSBONUS} 

all:		${NAME}
	 
clean:
				${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all	clean fclean re bonus