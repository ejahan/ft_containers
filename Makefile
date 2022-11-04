# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 17:49:12 by ejahan            #+#    #+#              #
#    Updated: 2022/11/04 00:27:57 by ejahan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.cpp

SRCS2		=	main_std.cpp

OBJS		=	${SRCS:.cpp=.o}

OBJS2		=	${SRCS2:.cpp=.o}

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra -std=c++98

NAME		=	ft_containers

NAME2		=	std_containers

RM			=	rm -rf

%.o:%.cpp
			${CC} -o $@ -c $< ${CFLAGS}

all:		${NAME} ${NAME2}

$(NAME):	${OBJS}
			${CC} -o ${NAME} ${OBJS} ${CFLAGS}

$(NAME2):	${OBJS2}
			${CC} -o ${NAME2} ${OBJS2} ${CFLAGS}

clean:
			${RM} ${OBJS}
			${RM} ${OBJS2}

fclean:		clean
			${RM} ${NAME}
			${RM} ${NAME2}

re:			fclean all

.PHONY: all clean fclean re
