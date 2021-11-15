/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:24:13 by merelmourik   #+#    #+#                 */
/*   Updated: 2021/11/15 20:07:53 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			kill_processes(t_data *data, int amount)
{
	int i;

	i = 0;
	while (i < amount)
	{
		kill(data->pid[i], SIGINT);
		i++;
	}
	exit(0);
}

int			clean_exit(t_data *data, t_philo *philo)
{
	if (data)
		free(data);
	if (philo)
		free(philo);
	if (data->message_sem)
		sem_close(data->message_sem);
	if (data->fork_sem)
		sem_close(data->fork_sem);
	if (data->pid)
		kill_processes(data, data->philo_amount);
	return (-1);
}
