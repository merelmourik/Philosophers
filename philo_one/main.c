/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:27:55 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/02 09:34:39 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philosopher_threads(t_philo *philo)
{
	pthread_t	*thread;
	int			i;

	thread = malloc(sizeof(pthread_t) * philo->data->philo_amount);
	i = 0;
	while (i < philo->data->philo_amount)
	{
		pthread_create(&thread[i], NULL, activate_philo, &philo[i]);
		i++;
		usleep(20);
	}
	i = 0;
	while (i < philo->data->philo_amount)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	free(thread);		//deze lost iets op
}

int		main(int argc, char **argv)
{
	t_data		*data;
	t_philo		*philo;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	if (initialize_input(argc, argv, data) == -1)
	{
		free(data);
		return (-1);
	}
	initialize_mutex(data);
	philo = initialize_philosophers(data);
	philosopher_threads(philo);
	free(philo);
	free(data->fork_mutex);		//alleen deze lijkt echt iets op te lossen
	// free(philo->data);
	// free(data->message);
	// free(data);
	// system("leaks philo_one");
	(void)argc;
	(void)argv;
	return (0);
}
