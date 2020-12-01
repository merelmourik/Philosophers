/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_one.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:30:17 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/01 13:48:34 by merelmourik   ########   odam.nl         */
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
	int				die;
	int				eat;
	int				sleep;
	int				repetition;			//ik kan ook op deze gaan tellen, maar alleen als ik met een pointer werk
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*message_mutex;		//geen pointer nodig?
	pthread_mutex_t *eat_mutex;		//nodig?
}					t_data;

typedef struct		s_philo
{
	int				id;
	int				time_to_die;
	int				repetition;
	int				left;
	int				right;
	t_data			*data;
	t_status		status;
}					t_philo;

int		ft_atoi(const char *str);
char	*time_stamp();
int		initialize_input(int argc, char **argv, t_data *data);;
void	*activate_philo(void *philosopher);
t_philo	*initialize_philosophers(t_data *data);
char	*long_to_str(unsigned long value);
int		ft_strlen(const char *str);
char	*itoa(unsigned int nb);
void	message(char *activity, t_philo *philo);
void	eating(t_philo *philo);

#endif
