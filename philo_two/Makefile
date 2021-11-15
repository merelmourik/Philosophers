# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: merelmourik <merelmourik@student.codam.      +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/17 14:16:03 by merelmourik   #+#    #+#                  #
#    Updated: 2021/11/15 20:10:37 by merelmourik   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo_two
SRCS = main.c utils.c initialize.c message.c eat.c free_and_exit.c
CC = gcc
CFLAGS = -I. -Wall -Werror -Wextra -g -pthread
AS = -I. -Wall -Werror -Wextra -g -fsanitize=address -O1 -fno-omit-frame-pointer
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I. $(SRCS) -o $(NAME)
	@echo "Done"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

surviving: all
	@./philo_two 50 1000 300 500 5

dying: all
	@./philo_two 5 100 50 50

two: all
	@./philo_two 2 100 30 50 5

forever: all
	@./philo_two 5 100 30 50

clean:
	@echo ">> Cleaning..."
	@$(RM) $(OBJS)

fclean: clean
	@rm -f *.o
	@rm -f philo_two

re: fclean all
