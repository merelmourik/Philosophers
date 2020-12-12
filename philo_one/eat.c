/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:06:43 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/12 10:28:17 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	pickup_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_lock(&(data->fork_mutex[philo->left]));
	message(" has taken a fork\n", philo);
	pthread_mutex_lock(&(data->fork_mutex[philo->right]));
	message(" has taken a fork\n", philo);
}

static void	laydown_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_unlock(&(data->fork_mutex[philo->left]));
	pthread_mutex_unlock(&(data->fork_mutex[philo->right]));
	//moeten deze beschermd worden? want kan eigelijk niet fout gaan
}

void	eating(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	if ((time_stamp() - philo->last_eaten) < (uint64_t)data->eat)
		{
			// message(" died", philo);
			philo->status = DEAD;
			return;
		}
	pickup_forks(philo);
	pthread_mutex_lock(data->eat_mutex);
	message(" is eating\n", philo);
	usleep(data->eat);
	pthread_mutex_unlock(data->eat_mutex);
	philo->last_eaten = time_stamp();
	laydown_forks(philo);
	if (data->repetition != -1)
		philo->repetition++;
}
