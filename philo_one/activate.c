/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   activate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 08:33:51 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/01 09:44:45 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	pickup_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_lock(&(data->fork_mutex[philo->left]));
	// hij moet hier wel wachten tot de eerste vork beschikbaar is voordat
	// hij de ander probeert te pakken
	message(" has taken a fork\n", philo->id);
	pthread_mutex_lock(&(data->fork_mutex[philo->right]));
	//pthread_join?
	message(" has taken a fork\n", philo->id);
}

void	laydown_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_unlock(&(data->fork_mutex[philo->left]));
	pthread_mutex_unlock(&(data->fork_mutex[philo->right]));
}

void	eating(t_philo *philo)
{
	pickup_forks(philo);
	message(" is eating\n", philo->id);
	//eat_lock?
	//eatlock omdat hij moet wachten tot hij is uitgegeten voordat hij verder gaat met slapen/denken
	usleep(philo->data->eat);
	laydown_forks(philo);
	philo->repetition++;
	
}

void	*activate_philo(void *philosopher)
{
	t_philo *philo;
	t_data	*data;

	philo = philosopher;
	data = philo->data;	
	while (philo->status == ALIVE && data->repetition > philo->repetition)
	{		
		eating(philo);
		message(" is sleeping\n", philo->id);
		message(" is thinking\n", philo->id);
		usleep(data->sleep);
	}
	return (NULL);
}
