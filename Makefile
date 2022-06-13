NAME		=	philo

SRCS		=	philo.c	utils.c simulation.c init.c validation.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
HEADER		=	philo.h

all			:	$(NAME)

%.o			:	%.c
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(OBJS) ${HEADER}
				@$(CC) ${CFLAGS} ${OBJS} -o $(NAME)
				@clear

clean		:
				${RM} $(OBJS)
				@clear

fclean		:	clean
				${RM} ${OBJS} $(NAME)
				@clear

re			:	fclean all

.PHONY		:	all clean fclean re
