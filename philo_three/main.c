/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:24:26 by merelmourik   #+#    #+#                 */
/*   Updated: 2021/11/15 20:08:04 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	*supervision(void *supervisor_philo)
{
	t_philo *philo;
	t_data	*data;

	philo = supervisor_philo;
	data = philo[0].data;
	while (1)
	{
		if (philo->status == DEAD)
		{
			usleep(100);
			message(" died\n", philo);
			data->status = DEAD;
			kill_processes(data, data->philo_amount);
		}
	}
	return (NULL);
}

static int	activate_philo(t_philo *philosopher, int i)
{
	t_data		*data;
	t_philo		*philo;
	pthread_t	main;

	philo = &philosopher[i];
	data = philo->data;
	philo->last_eaten = philo->start_time;
	if (pthread_create(&main, NULL, supervision, philo) != 0)
		return (-1);
	while (philo->status == ALIVE && (data->repetition == -1 || \
			data->repetition > philo->repetition))
	{
		eating(philo);
		if (philo->data->error == -1)
			return (-1);
		message(" is sleeping\n", philo);
		if (philo->data->error == -1)
			return (-1);
		message(" is thinking\n", philo);
		if (philo->data->error == -1)
			return (-1);
		ft_usleep(data->sleep, philo);
		if (philo->data->error == -1)
			return (-1);
	}
	return (0);
}

static int	philo_processes(t_philo *philo)	
{
	int			i;
	pid_t		pid;

	i = 0;
	while (i < philo->data->philo_amount)
	{
		pid = fork();
		if (pid == 0)
		{
			if (activate_philo(philo, i) == -1)
				return (-1);
			exit(0);
		}
		else
			philo->data->pid[i] = pid;
		i++;
		usleep(30);
	}
	i = 0;
	while (i < philo->data->philo_amount)
	{
		waitpid(philo->data->pid[i], NULL, 0);
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_data		*data;
	t_philo		*philo;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	if (initialize_input(argc, argv, data) == -1)
		return (clean_exit(data, NULL));
	if (initialize_semaphores(data) == -1)
		return (clean_exit(data, NULL));
	if (!(philo = initialize_philosophers(data)))
		return (clean_exit(data, philo));
	if (philo_processes(philo) == -1)
		clean_exit(data, philo);
	clean_exit(data, philo);
	return (0);
}
