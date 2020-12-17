/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:24:26 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/17 14:17:56 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	*activate_philo(void *philosopher)
{
	t_philo		*philo;
	t_data		*data;

	philo = philosopher;
	data = philo->data;
	philo->last_eaten = philo->start_time;
	while (data->status == ALIVE && (data->repetition == -1 || \
			data->repetition > philo->repetition))
	{
		eating(philo);
		if (philo->data->error == -1)
			return (NULL);
		message(" is sleeping\n", philo);
		if (philo->data->error == -1)
			return (NULL);
		message(" is thinking\n", philo);
		if (philo->data->error == -1)
			return (NULL);
		ft_usleep(data->sleep, philo);
		if (philo->data->error == -1)
			return (NULL);
	}
	return (NULL);
}

static int	philo_threads(t_philo *philo, pthread_t *thread, int i)
{
	i = 0;
	while (i < philo->data->philo_amount)
	{
		if (pthread_create(&thread[i], NULL, activate_philo, &philo[i]) != 0 \
			|| philo->data->error == -1)
		{
			free(thread);
			return (-1);
		}
		i++;
		usleep(30);
	}
	i = 0;
	while (i < philo->data->philo_amount)
	{
		if (pthread_join(thread[i], NULL) != 0)
		{
			free(thread);
			return (-1);
		}
		i++;
	}
	free(thread);
	return (0);
}

static void	*supervision(void *supervisor_philo)
{
	t_philo *philo;
	t_data	*data;
	int		i;

	philo = supervisor_philo;
	data = philo[0].data;
	while (1)
	{
		i = 0;
		while (i < data->philo_amount)
		{
			if (philo[i].status == DEAD)
			{
				message(" died\n", &philo[i]);
				if (philo->data->error == -1)
					return (NULL);
				data->status = DEAD;
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

static int	threads(t_philo *philo)
{
	pthread_t	supervisor;
	pthread_t	*thread;

	if (pthread_create(&supervisor, NULL, supervision, philo) != 0)
		return (-1);
	if (!(thread = malloc(sizeof(pthread_t) * philo->data->philo_amount)))
		return (-1);
	if (philo_threads(philo, thread, 0) == -1)
		return (-1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_data		*data;
	t_philo		*philo;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	if (initialize_input(argc, argv, data) == -1)
		return (clean_exit(data, NULL));
	if (initialize_semaphores(data) == -1)
		return (clean_exit(data, NULL));
	philo = initialize_philosophers(data);
	if (philo == NULL)
		return (clean_exit(data, philo));
	if (threads(philo) == -1)
		return (clean_exit(data, philo));
	clean_exit(data, philo);
	system("leaks philo_two");
	return (0);
}
