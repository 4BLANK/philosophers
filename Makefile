all:
	gcc -fsanitize=thread -g srcs/* -o philo
