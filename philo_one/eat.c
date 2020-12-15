/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:06:43 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/15 11:59:57 by merelmourik   ########   odam.nl         */
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
	if ((time_stamp() - philo->last_eaten) > data->die)
		{
			philo->status = DEAD;
			return;
		}
	pickup_forks(philo);
	pthread_mutex_lock(data->eat_mutex);
	message(" is eating\n", philo);
	philo->last_eaten = time_stamp();
	ft_usleep(data->eat);
	pthread_mutex_unlock(data->eat_mutex);
	laydown_forks(philo);
	if (data->repetition != -1)
		philo->repetition++;
	return ;
}
