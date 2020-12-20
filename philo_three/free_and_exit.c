/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:24:13 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/20 13:18:06 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			kill_processes(t_data *data, int amount)
{
	int i;

	i = -1;
	// printf("%d\n", amount);
	while (i < amount)
	{
		kill(data->pid[i], SIGINT);
		i++;
	// printf("HOOOI\n");
	}
	exit(0);	//data->pid niet freeen?

	system("leaks philo_three");
	// exit(0);
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
	if (data->pid)
		kill_processes(data, data->philo_amount);	
	exit(0);	//data->pid niet freeen?
	return (-1);
}
