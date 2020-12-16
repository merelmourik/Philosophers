/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:24:13 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/16 14:45:32 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int	destroy_mutexes(t_data *data, int amount)
{
	int i;

	i = 0;
	if (data->message_mutex)
		pthread_mutex_destroy(data->message_mutex);
	while (i < amount)
	{
		pthread_mutex_destroy(&data->fork_mutex[i]);
		i++;
	}
	return (-1);
}

int			clean_exit(t_data *data, t_philo *philo)
{
	if (philo)
		free(philo);
	if (data->message_mutex)
		free(data->message_mutex);
	if (data->fork_mutex)
		free(data->fork_mutex);
	free(data);
	return (destroy_mutexes(data, data->philo_amount));
}
