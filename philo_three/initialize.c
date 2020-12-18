/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:24:20 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/18 15:15:30 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		initialize_input(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
	{
		write(1, "Not the correct amount of arguments.\n", 38);
		return (-1);
	}
	data->philo_amount = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->repetition = ft_atoi(argv[5]);
	else
		data->repetition = -1;
	if ((data->philo_amount < 2 || data->die <= 0 || data->eat <= 0 || \
	data->sleep <= 0) || (argc == 6 && data->repetition <= 0))
	{
		write(1, "Invalid input\n", 15);
		return (-1);
	}
	return (0);
}

t_philo	*initialize_philosophers(t_data *data)
{
	t_philo	*philo;
	int		i;

	if (!(philo = malloc(sizeof(t_philo) * data->philo_amount)))
		return (NULL);		//is deze goed geprotect met freeen enzo?
	if (!(data->pid = malloc(sizeof(pid_t) * data->philo_amount)))
		return (NULL);		//eerst philo freeen? moet je uberhaupt malloccen hiervoor?
	i = 0;
	while (i < data->philo_amount)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].status = ALIVE;
		philo[i].repetition = 0;
		philo[i].start_time = time_stamp(philo);
		if (philo->data->error == -1)
			return (NULL);
		i++;
	}
	return (philo);
}

int		initialize_semaphores(t_data *data)
{
	data->message_sem = sem_open("/message_sem", O_CREAT, 0644, 1);
	data->fork_sem = sem_open("/fork_sem", O_CREAT, 0644, data->philo_amount);
	if (data->message_sem == SEM_FAILED || data->fork_sem == SEM_FAILED)
		return (-1);
	sem_unlink("/message_sem");
	sem_unlink("/fork_sem");
	return (0);
}
