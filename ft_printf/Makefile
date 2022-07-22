# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angassin <angassin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 11:34:06 by angassin          #+#    #+#              #
#    Updated: 2022/07/21 16:25:36 by angassin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c eval.c padding.c print_char.c print_integer.c \
			print_unsigned.c print_address.c 
				
OBJS 	=	$(addprefix srcs/, ${SRCS:.c=.o})

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -g3 

.c.o: 
			${CC} ${CFLAGS} -I./includes -c $< -o  ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
				make bonus -s -C libft
				cp libft/libft.a ${NAME}
				ar -rcvs ${NAME} ${OBJS}

bonus:		${NAME}	
			
clean:
		    	make -C libft clean
				${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
		    	make -C libft fclean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all	clean fclean re bonus 