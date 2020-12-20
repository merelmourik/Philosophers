/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:24:07 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/20 13:03:52 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	pickup_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	if (sem_wait(data->fork_sem) != 0)
	{
		data->error = -1;
		return ;
	}
	message(" has taken a fork\n", philo);
	if (philo->data->error == -1)
		return ;
	if (sem_wait(data->fork_sem) != 0)
	{
		data->error = -1;
		return ;
	}
	message(" has taken a fork\n", philo);
	if (philo->data->error == -1)
		return ;
}

static void	laydown_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	if (sem_post(data->fork_sem) != 0)
	{
		data->error = -1;
		return ;
	}
	if (sem_post(data->fork_sem) != 0)
	{
		data->error = -1;
		return ;
	}
	return ;
}

void	eating(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pickup_forks(philo);
	if (philo->data->error == -1)
		return ;
	if ((time_stamp(philo) - philo->last_eaten) > data->die)
	{
		if (data->error == -1)
			return ;
		// laydown_f÷orks(philo);
		philo->status = DEAD;
		exit(0);
		// message(" died\n", philo);
		// kill_processes(data, data->philo_amount);
		// exit(0);
		// printf("HOI\n");
		return ;
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
