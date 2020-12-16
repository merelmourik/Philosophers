/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:06:43 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/16 12:45:58 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	pickup_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	if (pthread_mutex_lock(&(data->fork_mutex[philo->left])) != 0)
		philo->data->error = -1;
	message(" has taken a fork\n", philo);
	if (pthread_mutex_lock(&(data->fork_mutex[philo->right])) != 0)
		philo->data->error = -1;
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
	if ((time_stamp() - philo->last_eaten) > data->die)		//eigenlijk deze ook beschermen
		{
			philo->status = DEAD;
			laydown_forks(philo);
			return ;
		}
	philo->last_eaten = time_stamp();
	message(" is eating\n", philo);
	if (ft_usleep(data->eat) == -1)
	{
		philo->data->error = -1;
		return ; 
	}
	laydown_forks(philo);
	if (philo->data->error == -1)
		return ;
	if (data->repetition != -1)
		philo->repetition++;
}
