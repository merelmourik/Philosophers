/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   activate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 08:33:51 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/11/30 10:20:05 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	message(t_status status, int id)
{
	char *str;

	if (status == FORK)
		str = " has taken a fork\n";
	id = 3;
// 	◦ timestamp_in_ms X has taken a fork
// ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died
}

//overdracht naar deze functie gaat ook goed
void	pickup_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_lock(&(data->fork_mutex[philo->left]));
	pthread_mutex_lock(&(data->fork_mutex[philo->right]));
	message(FORK, philo->id);
}


void	eating(t_philo *philo)
{
	pickup_forks(philo);
	
	philo->repetition -= 1;
}

void	*activate_philo(void *philosopher)
{
	t_philo *philo;
	static int i;

	philo = philosopher;
	i = 0;
	while (philo[i].status == ALIVE || philo[i].repetition != 0)
	{
		eating(&philo[i]);
		// sleeping(philo[i]);
		// thinking(philo[i]);
		i++;
	}
	printf("id = %d\n", philo[i].id);
	return (NULL);
}
