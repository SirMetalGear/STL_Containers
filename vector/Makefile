DIR		= ./../utils

SRCS	= main.cpp

OBJS	= ${SRCS:.cpp=.o}

NAME	= a.out

HEADER	= vector.hpp

CC		= clang++

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

%.o: %.cpp $(HEADER)
		${CC} ${CFLAGS} -I. -c $< -o ${<:.cpp=.o}

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		re all clean fclean