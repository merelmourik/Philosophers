/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   activate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 08:33:51 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/08 00:54:04 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*supervision(void *philosophers)
{
	t_philo **philo;
	t_data *data;
	int i;

	philo = philosophers;
	data = philo[0]->data;
	while(1)		//is deze nodig?
		{
			i = 0;
			while (i < data->philo_amount)
			{
				if (philo[i]->status == DEAD)
					{
						message(" died", philo[i]);
						return (NULL);		//is dit een goede return?
					}
				i++;
			}
		}
	return (NULL);
}

void	*activate_philo(void *philosopher)
{
	t_philo 	*philo;
	t_data		*data;
	pthread_t	*supervisor;

	if (!(supervisor = malloc(sizeof(pthread_t))))
		return (-1);
	if (pthread_create(supervisor, NULL, supervision, philo) != 0)
	{
		free(supervisor);
		return (NULL);			//is deze error duidleijk genoeg?
	}
	philo = philosopher;
	data = philo->data;	
	philo->last_eaten = philo->start_time;
	while (philo->status == ALIVE && (data->repetition == -1 || data->repetition > philo->repetition))
	{		
		eating(philo);
		message(" is sleeping\n", philo);
		message(" is thinking\n", philo);
		usleep(data->sleep);
	}
	return (NULL);
}
