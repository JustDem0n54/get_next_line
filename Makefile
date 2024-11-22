NAME	= GNL.a

LIBC	= get_next_line.c get_next_line_utils.c

SRCS	= ${LIBC}

OBJS	= ${SRCS:.c=.o}

CC		= cc
RM		= rm -rf
AR		= ar rc

CFLAGS	= -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
