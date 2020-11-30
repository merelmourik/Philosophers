/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 10:43:04 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/11/30 11:29:51 by merelmourik   ########   odam.nl         */
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
}

void	message(t_status status, int id)
{
	char 	*activity;
	char	*str;

	if (status == FORK)
		activity = " has taken a fork\n";
	if (status == EATING)
		activity = " is eating\n";
	str = time_stamp();
	write(1, str, ft_strlen(str));
	write(1, " ", 1);
	str = itoa(id);
	write(1, str, ft_strlen(str));
	write(1, activity, ft_strlen(activity));
// 	◦ timestamp_in_ms X has taken a fork
// ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died
}