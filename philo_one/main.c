/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:27:55 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/11/29 14:25:54 by merelmourik   ########   odam.nl         */
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
		philo[i].amount_eaten = 0;
		philo[i].alive = 0;
		i++;
	}
	return (philo);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_philo		*philo;
	pthread_t	*thread;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	if (validate_input(argc, argv, data) == -1)
	{
		free(data);
		return (-1);
	}
	thread = malloc(sizeof(pthread_t) * data->philo_amount);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philo_amount);
	philo = initialize_philosophers(data);
	// int i = 0;
	// while (i < data->philo_amount){
	// 	printf("id philo = %d\n", philo[i].id);
	// 	i++;
	// }
	system("leaks philo_one");
	return (0);
}
