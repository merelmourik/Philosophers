#include "philo_one.h"

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int res;

    i = 0;
    sign = 1;
    res = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while(str[i] >= '0' && str[i] <= '9' && str[i])
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    if (res == 0)
        return(0);
    return (res * sign);
}