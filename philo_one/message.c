/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 10:43:04 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/08 00:02:56 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long	time_stamp(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (current.tv_sec * 1000 + current.tv_usec / 1000);
}

void	message(char *activity, t_philo *philo)
{
	char		*str;
	t_data		*data;
	uint64_t	time;

	data = philo->data;	
	pthread_mutex_lock(data->message_mutex);
	time = time_stamp() - philo->start_time;
	str = long_to_str(time);
	write(1, str, ft_strlen(str));
	write(1, "\t", 1);
	free(str);
	str = itoa(philo->id);
	write(1, str, ft_strlen(str));
	free(str);
	write(1, activity, ft_strlen(activity));
	pthread_mutex_unlock(data->message_mutex);
}