/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   activate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 08:33:51 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/11/30 11:59:19 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

//overdracht naar deze functie gaat ook goed
void	pickup_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_lock(&(data->fork_mutex[philo->left]));
	message(FORK, philo->id);
	pthread_mutex_lock(&(data->fork_mutex[philo->right]));
	message(FORK, philo->id);
	printf("%d en %d\n", philo->left, philo->right);
}

void	laydown_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_unlock(&(data->fork_mutex[philo->left]));
	pthread_mutex_unlock(&(data->fork_mutex[philo->right]));
}

void	eating(t_philo *philo)
{
	pickup_forks(philo);
	message(EATING, philo->id);
	usleep(philo->data->eat);		//gaat het hier fout?
	laydown_forks(philo);
	philo->data->repetition--;
}

void	*activate_philo(void *philosopher)
{
	t_philo *philo;

	philo = philosopher;		//dit is een kopie en dat is kut, maar de data vewijst wel naar een geheugenadres
	while (philo->status == ALIVE || philo->data->repetition > 0)		// >= ?
	{
		eating(philo);
		printf("\n");
		// sleeping(philo[i]);
		// thinking(philo[i]);
	}
	printf("id = %d\n", philo->id);
	return (NULL);
}

// static void	*philo_loop(void *v_philo)
// {
// 	t_data		*data;
// 	t_philo		*philo;
// 	pthread_t	pid;

// 	philo = (t_philo*)v_philo;
// 	data = philo->data;
// 	philo->last_eaten = time_stamp();
// 	if (pthread_create(&pid, NULL, monitor, philo) != 0)
// 		return (NULL);
// 	while (data->state == ALIVE && philo->amount_eaten != data->amount_to_eat)
// 	{
// 		philo_write(philo, "is thinking");
// 		philo_eat(philo);
// 		philo_write(philo, "is sleeping");
// 		ft_usleep(data->sleep_time);
// 	}
// 	pthread_join(pid, NULL);
// 	return (NULL);
// }