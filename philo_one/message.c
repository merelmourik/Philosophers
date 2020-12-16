/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 10:43:04 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/16 12:40:22 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int64_t	time_stamp(void)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
		return (-1);
	return (current.tv_sec * 1000 + current.tv_usec / 1000);
}

void	message(char *activity, t_philo *philo)
{
	t_data		*data;
	uint64_t	time;

	data = philo->data;	
	pthread_mutex_lock(data->message_mutex);
	if (data->status == DEAD)
	{
		pthread_mutex_unlock(data->message_mutex);
		return ;
	}
	time = time_stamp() - philo->start_time;
	ft_putnumber(time);
	write(1, "\t", 1);
	ft_putnumber(philo->id);
	write(1, activity, ft_strlen(activity));
	pthread_mutex_unlock(data->message_mutex);
}