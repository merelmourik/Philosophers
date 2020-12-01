/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 10:43:04 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/01 09:40:53 by merelmourik   ########   odam.nl         */
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

void	message(char *activity, int id)
{
	char	*str;

	str = time_stamp();
	write(1, str, ft_strlen(str));
	write(1, " ", 1);
	free(str);
	str = itoa(id);
	write(1, str, ft_strlen(str));
	free(str);
	write(1, activity, ft_strlen(activity));
}