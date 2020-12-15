/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   activate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 08:33:51 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/15 11:57:43 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*activate_philo(void *philosopher)
{
	t_philo 	*philo;
	t_data		*data;

	philo = philosopher;
	data = philo->data;	
	philo->last_eaten = philo->start_time;
	while (data->status == ALIVE && (data->repetition == -1 || data->repetition > philo->repetition))
	{		
		eating(philo);
		message(" is sleeping\n", philo);
		message(" is thinking\n", philo);
		ft_usleep(data->sleep);
	}
	return (NULL);		
}
