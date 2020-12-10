/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   activate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 08:33:51 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/10 11:33:55 by mmourik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*supervision(void *philo)
{			//deze communiceert niet met activate_philo
	t_philo *philosophers;
	t_data 	*data;
	int		i;

	philosophers = philo;
	data = philosophers[0].data;
	while(1)		//is deze nodig?
	{
		i = 0;
		while (i < data->philo_amount)
		{
			if (philosophers[i].status == DEAD)
			{
				message(" died\n", &philosophers[i]);
				pthread_mutex_lock(data->eat_mutex);
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
	pthread_t	*supervisor;		//deze free ook toevoegen

	philo = philosopher;
	data = philo->data;	
	philo->last_eaten = philo->start_time;
	if (!(supervisor = malloc(sizeof(pthread_t))))
		return (NULL);		//eerst thread freeen
	if (pthread_create(supervisor, NULL, supervision, philo) != 0)
	{
		free(supervisor);		//and thread
		return (NULL);			//is deze error duidleijk genoeg?
	}
	while (philo->status == ALIVE && (data->repetition == -1 || data->repetition > philo->repetition))
	{		
		eating(philo);
		message(" is sleeping\n", philo);
		message(" is thinking\n", philo);
		usleep(data->sleep);
	}
	return (NULL);		//uitzoeken welke return het moet zijn
}
