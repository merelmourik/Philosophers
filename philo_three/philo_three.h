/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_three.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:30:17 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/18 12:07:53 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <string.h>
# include <pthread.h>
# include <signal.h>

typedef enum		e_status {
	ALIVE,
	DEAD,
}					t_status;

typedef struct		s_data {
	int				philo_amount;
	int				repetition;
	int				error;
	pid_t			*pid;
	uint64_t		die;
	int64_t			eat;
	int64_t			sleep;
	sem_t			*fork_sem;
	sem_t			*message_sem;
	t_status		status;
}					t_data;

typedef struct		s_philo
{
	int				id;
	int				time_to_die;
	int				repetition;
	pid_t			pid;
	uint64_t		last_eaten;
	uint64_t		start_time;
	t_data			*data;
	t_status		status;
}					t_philo;

int		clean_exit(t_data *data, t_philo *philo);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		initialize_input(int argc, char **argv, t_data *data);;
int		initialize_semaphores(t_data *data);

int64_t time_stamp(t_philo *philo);
t_philo	*initialize_philosophers(t_data *data);

void	eating(t_philo *philo);
void	ft_putnumber(unsigned long n);
void	ft_usleep(int64_t wait_time, t_philo *philo);
void	*kill_processes(t_data *data, int i);
void	message(char *activity, t_philo *philo);

#endif
