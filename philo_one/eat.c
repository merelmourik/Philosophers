/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:06:43 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/16 12:20:49 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	pickup_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	if (pthread_mutex_lock(&(data->fork_mutex[philo->left])) != 0)
		return (-1);
	message(" has taken a fork\n", philo);
	if (pthread_mutex_lock(&(data->fork_mutex[philo->right])) != 0)
		return (-1);
	message(" has taken a fork\n", philo);
	return (0);
}

static int	laydown_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	if (pthread_mutex_unlock(&(data->fork_mutex[philo->left])) != 0)
		return (-1);
	if (pthread_mutex_unlock(&(data->fork_mutex[philo->right])) != 0)
		return (-1);
	return (0);
}

void	eating(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	if (pickup_forks(philo) == -1)
	{
		philo->data->error = -1;
		return ;
	}
	if ((time_stamp() - philo->last_eaten) > data->die)
		{
			philo->status = DEAD;
			laydown_forks(philo);
			return ;
		}
	philo->last_eaten = time_stamp();
	message(" is eating\n", philo);
	ft_usleep(data->eat);
	if (laydown_forks(philo) == -1)
	{
		philo->data->error = -1;
		return ;
	}
	if (data->repetition != -1)
		philo->repetition++;
	return ;
}
