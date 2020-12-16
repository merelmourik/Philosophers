/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:27:55 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/16 10:47:58 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*supervision(void *supervisor_philo)		//deze code herschrijven met data struct zodat hij sneller communiceert
{
	t_philo *philo;	
	t_data 	*data;
	int		i;

	philo = supervisor_philo;
	data = philo[0].data;
	while(1)		//is deze nodig?
	{
		i = 0;
		while (i < data->philo_amount)
		{
			if (philo[i].status == DEAD)		//veranderen voor data struct
			{
				message(" died\n", &philo[i]);
				data->status = DEAD;
				return (NULL);		//is dit een goede return?
			}
			i++;
		}
	}
	return (NULL);
}

int	philosopher_threads(t_philo *philo)
{
	pthread_t	*thread;			//ik kan deze threads ook vanuit de main meesturen of in een struct doen
	pthread_t	*supervisor;		//deze free ook toevoegen
	int			i;					

	if (!(thread = malloc(sizeof(pthread_t) * philo->data->philo_amount)))
		return (-1);
	if (!(supervisor = malloc(sizeof(pthread_t))))
		return (-1);		//eerst thread freeen
	if (pthread_create(supervisor, NULL, supervision, philo) != 0)
	{
		free(supervisor);		//and free thread
		return (-1);			//is deze error duidleijk genoeg?
	}
	i = 0;
	while (i < philo->data->philo_amount)
	{
		if (pthread_create(&thread[i], NULL, activate_philo, &philo[i]) != 0)
		{
			free(thread);
			return (-1);
		}
		i++;
		usleep(30);			//is dit de reden dat ze nooit dood gaan?
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

// - Do not test with more than 200 philosphers
// - Do not test with time_to_die or time_to_eat or time_to_sleep under 60 ms
// - Test with 5 800 200 200, no one should die!
// - Test with 5 800 200 200 7, no one should die and the simulation should stop when all the philosopher has eaten at least 7 times each.
// - Test with 4 410 200 200, no one should die!
// - Test with 4 310 200 100, a philosopher should die!
// - Test with 2 philosophers and check the different times (a death delayed by more than 10 ms is unacceptable).