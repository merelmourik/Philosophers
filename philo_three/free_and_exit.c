/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:24:13 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/17 14:17:50 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			clean_exit(t_data *data, t_philo *philo)
{
	free(data);
	if (philo)
		free(philo);
	if (data->message_sem)
		sem_close(data->message_sem);
	if (data->fork_sem)
		sem_close(data->fork_sem);
	return (-1);
}
