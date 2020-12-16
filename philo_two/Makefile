NAME = philo_two
SRCS = main.c utils.c initialize.c message.c eat.c free_and_exit.c
CC = gcc
CFLAGS = -I. -Wall -Werror -Wextra -g -lpthread -pthread		#delete the thread
AS = -I. -Wall -Werror -Wextra -g -fsanitize=address -O1 -fno-omit-frame-pointer
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I. $(SRCS) -o $(NAME)
	@echo "Done"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo ">> Cleaning..."
	@$(RM) $(OBJS)

fclean: clean
	@rm -f *.o
	@rm -f philo_one

re: fclean all