CC= cc
CFLAGS= -Wall -Werror -Wextra
SRCS= ./srcs/misc.c \
			./srcs/time.c \
			./srcs/clean.c \
			./srcs/misc2.c \
			./srcs/misc3.c \
			./srcs/ryuku.c \
			./srcs/start.c \
			./srcs/params.c \
			./srcs/create_lists.c \
			./srcs/philosophers.c \
			./srcs/error_handling.c
NAME= philo
OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf srcs/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
#
# all:
# 	gcc -Wall -Werror -Wextra srcs/* -o philo
# 	#gcc -fsanitize=thread -g srcs/* -o philo
