CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
SRCS = philo.c ft_atoi.c parce.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re