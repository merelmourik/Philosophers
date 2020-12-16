/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:06:43 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/16 12:59:35 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	pickup_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	if (pthread_mutex_lock(&(data->fork_mutex[philo->left])) != 0)
	{
		philo->data->error = -1;
		return ;
	}
	message(" has taken a fork\n", philo);
	if (philo->data->error == -1)
		return ;
	if (pthread_mutex_lock(&(data->fork_mutex[philo->right])) != 0)
	{
		philo->data->error = -1;
		return ;
	}
	message(" has taken a fork\n", philo);
}

static void	laydown_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	if (pthread_mutex_unlock(&(data->fork_mutex[philo->left])) != 0)
		philo->data->error = -1;
	if (pthread_mutex_unlock(&(data->fork_mutex[philo->right])) != 0)
		philo->data->error = -1;
}

void	eating(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pickup_forks(philo);
	if (philo->data->error == -1)
		return ;
	if ((time_stamp(philo) - philo->last_eaten) > data->die)		//eigenlijk deze ook beschermen
		{		//deze time_stamp kan beter worden beschermd
			philo->status = DEAD;
			return (laydown_forks(philo));
		}
	philo->last_eaten = time_stamp(philo);
	message(" is eating\n", philo);
	if (philo->data->error == -1)
		return (laydown_forks(philo));
	ft_usleep(data->eat, philo);
	if (philo->data->error == -1)
		return (laydown_forks(philo));
	laydown_forks(philo);
	if (philo->data->error == -1)
		return ;
	if (data->repetition != -1)
		philo->repetition++;
}
