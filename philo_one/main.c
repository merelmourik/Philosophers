/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:27:55 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/08 00:07:54 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	philosopher_threads(t_philo *philo)
{
	pthread_t	*thread;
	int			i;

	if (!(thread = malloc(sizeof(pthread_t) * philo->data->philo_amount)))
		return (-1);
	i = 0;
	while (i < philo->data->philo_amount)
	{
		if (pthread_create(&thread[i], NULL, activate_philo, &philo[i]) != 0)
		{
			free(thread);
			return (-1);
		}
		i++;
		usleep(100);
	}
	i = 0;
	while (i < philo->data->philo_amount)
	{
		if (pthread_join(thread[i], NULL) != 0)
			{
				free (thread);
				return (-1);
			}
		i++;
	}
	free(thread);
	return (0);
}

int		main(int argc, char **argv)
{
	t_data		*data;
	t_philo		*philo;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	if (initialize_input(argc, argv, data) == -1)
		return (clean_exit(data, NULL));
	if (initialize_mutex(data) == -1)
		return (clean_exit(data, NULL));
	philo = initialize_philosophers(data);
	if (philo == NULL)
		return (clean_exit(data, philo));
	if (philosopher_threads(philo) == -1)
		return (clean_exit(data, philo));
	clean_exit(data, philo);
	// system("leaks philo_one");
	return (0);
}
