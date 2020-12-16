/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:24:32 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/16 14:45:44 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int64_t	time_stamp(t_philo *philo)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
	{
		philo->data->error = -1;
		return (-1);
	}
	return (current.tv_sec * 1000 + current.tv_usec / 1000);
}

void	message(char *activity, t_philo *philo)
{
	t_data		*data;
	uint64_t	time;

	data = philo->data;
	if (pthread_mutex_lock(data->message_mutex) != 0)
	{
		philo->data->error = -1;
		return ;
	}
	if (data->status == DEAD)
	{
		pthread_mutex_unlock(data->message_mutex);
		return ;
	}
	time = time_stamp(philo) - philo->start_time;
	if (philo->data->error == -1)
		return ;
	ft_putnumber(time);
	write(1, "\t", 1);
	ft_putnumber(philo->id);
	write(1, activity, ft_strlen(activity));
	if (pthread_mutex_unlock(data->message_mutex) != 0)
		philo->data->error = -1;
}