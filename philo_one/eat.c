/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:06:43 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/02 09:32:25 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	pickup_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_lock(&(data->fork_mutex[philo->left]));
	message(" has taken his left fork\n", philo);
	pthread_mutex_lock(&(data->fork_mutex[philo->right]));
	message(" has taken his right fork\n", philo);
}

static void	laydown_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_unlock(&(data->fork_mutex[philo->left]));
	pthread_mutex_unlock(&(data->fork_mutex[philo->right]));
}

void	eating(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pickup_forks(philo);
	// pthread_mutex_lock(philo->eat_mutex);
	message(" is eating\n", philo);
	usleep(philo->data->eat);
	laydown_forks(philo);
	// pthread_mutex_unlock(philo->eat_mutex);
	philo->repetition++;
}
