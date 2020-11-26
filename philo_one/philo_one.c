/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_one.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:27:55 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/11/26 15:40:50 by mmourik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*the_table(void *data_ptr)
{
	t_data *data;

	data = (t_data*)data_ptr;
	printf("%d\n", data->eat);
	// long time = time_stamp();
	// if (data->index < data->philo)
		// printf("Philo number %d is created at %ld\n", data->index, time);
	data->index++;
	return NULL;
}

int		create_philosophers(t_data *data)
{
	int i;
	pthread_t thread[data->philo];
	
	i = 0;
	while (i < data->philo)
	{
		pthread_create(&(thread[i]), NULL, &the_table, &data);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data *data;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	if (validate_input(argc, argv, data) == -1)
	{
		free(data);
		return (-1);
	}
	create_philosophers(data);
	// printf("%d\n", data->eat);
	system("leaks philo_one");
	return (0);
}
