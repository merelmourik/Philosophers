/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 10:43:04 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/01 13:32:21 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

char		*time_stamp(void)
{
	struct timeval	current;
	unsigned long	stamp;

	gettimeofday(&current, NULL);
	stamp = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (long_to_str(stamp));
}			//is dit de juiste timestamp?

void	message(char *activity, t_philo *philo)
{
	char	*str;
	t_data	*data;

	data = philo->data;	
	// pthread_mutex_lock(data->message_mutex);
	// str = time_stamp();
	// write(1, str, ft_strlen(str));
	// write(1, " ", 1);
	// free(str);
	str = itoa(philo->id);
	write(1, str, ft_strlen(str));
	free(str);
	write(1, activity, ft_strlen(activity));
	// pthread_mutex_unlock(data->message_mutex);
}