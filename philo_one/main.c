/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:27:55 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/10 11:29:10 by mmourik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

// void	*supervision(void *supervisor_philo)
// {			//deze communiceert niet met activate_philo
// 	t_philo *supervisor;
// 	t_data 	*data;
// 	int		i;

// 	supervisor = supervisor_philo;
// 	data = supervisor[0].data;
// 	while(1)		//is deze nodig?
// 	{
// 		i = 0;
// 		while (i < data->philo_amount)
// 		{
// 			if (supervisor[i].status == DEAD)
// 			{
// 				message(" died\n", &supervisor[i]);
// 				pthread_mutex_lock(data->eat_mutex);
// 				return (NULL);		//is dit een goede return?
// 			}
// 			i++;
// 		}
// 	}
// 	return (NULL);
// }

int	philosopher_threads(t_philo *philo)
{
	pthread_t	*thread;
	// pthread_t	*supervisor;		//deze free ook toevoegen
	int			i;					//misschien beter ook in data struct stoppen?

	if (!(thread = malloc(sizeof(pthread_t) * philo->data->philo_amount)))
		return (-1);
	// if (!(supervisor = malloc(sizeof(pthread_t))))
	// 	return (-1);		//eerst thread freeen
	// if (pthread_create(supervisor, NULL, supervision, philo) != 0)
	// {
	// 	free(supervisor);		//and thread
	// 	return (-1);			//is deze error duidleijk genoeg?
	// }
	i = 0;
	while (i < philo->data->philo_amount)
	{
		if (pthread_create(&thread[i], NULL, activate_philo, &philo[i]) != 0)
		{
			free(thread);
			return (-1);
		}
		i++;
		usleep(100);
	}
	i = 0;
	while (i < philo->data->philo_amount)
	{
		if (pthread_join(thread[i], NULL) != 0)
			{
				free (thread);
				return (-1);
			}
		i++;
	}
	free(thread);
	return (0);
}

int		main(int argc, char **argv)
{
	t_data		*data;
	t_philo		*philo;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	if (initialize_input(argc, argv, data) == -1)
		return (clean_exit(data, NULL));
	if (initialize_mutex(data) == -1)
		return (clean_exit(data, NULL));
	philo = initialize_philosophers(data);
	if (philo == NULL)
		return (clean_exit(data, philo));
	if (philosopher_threads(philo) == -1)
		return (clean_exit(data, philo));
	clean_exit(data, philo);
	// system("leaks philo_one");
	return (0);
}
