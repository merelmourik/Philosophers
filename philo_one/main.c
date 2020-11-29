/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:27:55 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/11/29 17:07:58 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philo	*initialize_philosophers(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * data->philo_amount);
	i = 0;
	while (i < data->philo_amount)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].repetition = 0;
		philo[i].left = i;
		// nog even checken of deze gedachte gang klopt
		philo[i].right = (i == data->philo_amount - 1 ? 0 : i + 1);
		philo[i].status = ALIVE;
		i++;
	}
	return (philo);
}

void	*activate_philo(void *philosopher)
{
	t_philo *philo;

	philo = philosopher;
	return NULL;
}

void	philosopher_threads(t_philo *philo)
{
	pthread_t	*thread;
	int			i;

	thread = malloc(sizeof(pthread_t) * philo->data->philo_amount);
	i = 0;
	while (i < philo->data->philo_amount)
	{
		pthread_create(&thread[i], NULL, activate_philo, &philo[i]);
		pthread_join(thread[i], NULL);
		i++;
	}
	free (thread);
}

int		main(int argc, char **argv)
{
	t_data		*data;
	t_philo		*philo;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	if (validate_input(argc, argv, data) == -1)
	{
		free(data);
		return (-1);
	}
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philo_amount);
	philo = initialize_philosophers(data);
	// free(data);
	philosopher_threads(philo);
	// ik heb genoeg threads and ik heb aan de filosofen de juiste data gegeven
	// maar nu moet elke filosoof ook nog aan thread worden gekoppeld
	// int i = 0;
	// while (i < data->philo_amount){
	// 	printf("id philo = %d\n", philo[i].id);
	// 	i++;
	// }
	free(philo);
	free(data->fork);
	system("leaks philo_one");
	return (0);
}
