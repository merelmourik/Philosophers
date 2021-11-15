# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: merelmourik <merelmourik@student.codam.      +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/17 14:15:50 by merelmourik   #+#    #+#                  #
#    Updated: 2021/11/15 20:10:50 by merelmourik   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
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
	@./philo_one 50 1000 300 500 5

dying: all
	@./philo_one 5 100 50 50

two: all
	@./philo_one 2 100 30 50 5

forever: all
	@./philo_one 5 100 30 50

clean:
	@echo ">> Cleaning..."
	@$(RM) $(OBJS)

fclean: clean
	@rm -f *.o
	@rm -f philo_one

re: fclean all
