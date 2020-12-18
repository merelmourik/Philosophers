/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:24:13 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/18 12:46:50 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*kill_processes(t_data *data, int i)
{
	int j;

	j = 0;
	while(j < i)			//||<=?
	{
		kill(data->pid[i], SIGINT);
		i++;
	}
	return (NULL);
}

int			clean_exit(t_data *data, t_philo *philo)
{
	free(data);
	if (philo)
		free(philo);
	if (data->message_sem)
		sem_close(data->message_sem);
	if (data->fork_sem)
		sem_close(data->fork_sem);
	system("leaks philo_three");			//deleten
	if (data->pid)
		kill_processes(data, data->philo_amount);		//data->pid niet freeen?
	return (-1);
}
