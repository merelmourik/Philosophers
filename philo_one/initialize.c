/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 08:32:31 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/17 14:13:17 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		initialize_input(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
	{
		write(1, "Not the correct amount of arguments.\n", 38);
		return (-1);
	}
	data->philo_amount = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->repetition = ft_atoi(argv[5]);
	else
		data->repetition = -1;
	if ((data->philo_amount < 2 || data->die <= 0 || data->eat <= 0 || \
	data->sleep <= 0) || (argc == 6 && data->repetition <= 0))
	{
		write(1, "Invalid input\n", 15);
		return (-1);
	}
	return (0);
}

t_philo	*initialize_philosophers(t_data *data)
{
	t_philo	*philo;
	int		i;

	data->error = 0;
	if (!(philo = malloc(sizeof(t_philo) * data->philo_amount)))
		return (NULL);
	i = 0;
	while (i < data->philo_amount)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].left = i;
		philo[i].right = (i == data->philo_amount - 1 ? 0 : i + 1);
		philo[i].status = ALIVE;
		philo[i].repetition = 0;
		philo[i].start_time = time_stamp(philo);
		if (philo->data->error == -1)
			return (NULL);
		i++;
	}
	return (philo);
}

int		initialize_mutex(t_data *data)
{
	int i;

	i = 0;
	data->message_mutex = malloc(sizeof(pthread_mutex_t));
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->philo_amount);
	if (!data->fork_mutex || !data->message_mutex)
		return (-1);
	if (pthread_mutex_init(data->message_mutex, NULL) != 0)
		return (-1);
	while (i < data->philo_amount)
	{
		if (pthread_mutex_init(&(data->fork_mutex[i]), NULL) != 0)
		{
			data->philo_amount = i;
			return (-1);
		}
		i++;
	}
	return (0);
}
