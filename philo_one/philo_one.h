/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_one.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:30:17 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/11/29 16:55:27 by merelmourik   ########   odam.nl         */
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
	DEAD
}					t_status;

typedef struct		s_data {
	int				philo_amount;
	int				die;
	int				eat;
	int				sleep;
	int				repetition;
	pthread_mutex_t	*fork;
}					t_data;

typedef struct		s_philo
{
	int				id;
	int				time_until_death;
	int				start;
	int				repetition;
	int				left;
	int				right;
	pthread_mutex_t	talking;
	t_data			*data;
	t_status		status;
}					t_philo;

int		ft_atoi(const char *str);
long	time_stamp();
int		validate_input(int argc, char **argv, t_data *data);;

#endif
