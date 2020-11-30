/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_one.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:30:17 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/11/30 10:16:32 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef enum		e_status {
	ALIVE,
	DEAD,
	EATING,
	FORK,
	SLEEPING,
	THINKING
}					t_status;

typedef struct		s_data {
	int				philo_amount;
	int				die;
	int				eat;
	int				sleep;
	int				repetition;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*message;
}					t_data;

typedef struct		s_philo
{
	int				id;
	int				time_until_death;
	int				start;
	int				repetition;
	int				left;
	int				right;
	t_data			*data;
	t_status		status;
}					t_philo;

int				ft_atoi(const char *str);
unsigned long	time_stamp();
int				initialize_input(int argc, char **argv, t_data *data);;
void			*activate_philo(void *philosopher);
t_philo			*initialize_philosophers(t_data *data);
char			*long_to_str(unsigned long value);


#endif
