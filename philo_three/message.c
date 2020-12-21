/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:24:32 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/21 09:56:25 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
	sem_wait(data->message_sem);
	time = time_stamp(philo) - philo->start_time;
	if (philo->data->error == -1)
		return ;
	ft_putnumber(time);
	write(1, "\t", 1);
	ft_putnumber(philo->id);
	write(1, activity, ft_strlen(activity));
	sem_post(data->message_sem);
}
