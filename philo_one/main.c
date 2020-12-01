/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:27:55 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/01 09:56:52 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

// in onderstaande functie worden de waardes goed ontvangen
void	philosopher_threads(t_philo *philo)
{
	pthread_t	*thread;
	int			i;

	thread = malloc(sizeof(pthread_t) * philo->data->philo_amount);
	i = 0;
	while (i < philo->data->philo_amount)
	{
		pthread_create(&thread[i], NULL, activate_philo, &philo[i]);
		// pthread_join(thread[i], NULL);			//wachten tot vorige thread klaar is
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
	philo = initialize_philosophers(data);
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->philo_amount);
	data->message = malloc(sizeof(pthread_mutex_t));
	philosopher_threads(philo);
	free(philo);
	free(data->fork_mutex);		//alleen deze lijkt echt iets op te lossen
	// free(philo->data);
	// free(data->message);
	// free(data);
	system("leaks philo_one");
	(void)argc;
	(void)argv;
	return (0);
}
