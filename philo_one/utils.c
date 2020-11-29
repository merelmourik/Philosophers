#include "philo_one.h"

int     ft_atoi(const char *str)
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

long     time_stamp()
{
    struct  timeval current;
    long    stamp;

    gettimeofday(&current, NULL);
    stamp = current.tv_sec * 1000 + current.tv_usec / 1000;
    return (stamp);
}

int	validate_input(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
	{
		write(1, "Not the correct amount of arguments\n", 37);
		return (-1);
	}
	data->philo_amount = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->repetition = ft_atoi(argv[5]);
	if ((data->philo_amount < 2 || data->die <= 0 || data->eat <= 0 || \
	data->sleep <= 0) || (argc == 6 && data->repetition <= 0))
	{
		write(1, "Invalid input\n", 15);
		return (-1);
	}
	return (0);
}