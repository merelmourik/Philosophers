#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct  s_philo {
    int     philo;
    int     die;
    int     eat;
    int     sleep;
    int     repetition;
}               t_philo;

int ft_atoi(const char *str);