/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_one.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:30:17 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/16 12:53:20 by merelmourik   ########   odam.nl         */
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
}					t_status;

typedef struct		s_data {
	int				philo_amount;
	int				repetition;
	int				error;
	uint64_t		die;
	int64_t			eat;
	int64_t			sleep;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*message_mutex;		//geen pointer nodig?
	t_status		status;
}					t_data;

typedef struct		s_philo
{
	int				id;
	int				time_to_die;
	int				repetition;
	int				left;
	int				right;
	uint64_t		last_eaten;
	uint64_t		start_time;
	t_data			*data;
	t_status		status;
}					t_philo;

int		ft_atoi(const char *str);
int64_t time_stamp(t_philo *philo);
int		initialize_input(int argc, char **argv, t_data *data);;
t_philo	*initialize_philosophers(t_data *data);
int		ft_strlen(const char *str);
void	message(char *activity, t_philo *philo);
void	eating(t_philo *philo);
int		initialize_mutex(t_data *data);
int		clean_exit(t_data *data, t_philo *philo);
void		ft_usleep(int64_t wait_time, t_philo *philo);
void ft_putnumber(unsigned long n);

#endif
