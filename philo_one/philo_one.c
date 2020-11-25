/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_one.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:27:55 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/11/25 12:32:40 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	validate_input(int argc, char **argv, t_philo *philo)
{
	if (argc != 5 && argc != 6)
	{
		write(1, "Not the correct amount of arguments\n", 37);
		return (-1);
	}
	philo->philo = ft_atoi(argv[1]);
	philo->die = ft_atoi(argv[2]);
	philo->eat = ft_atoi(argv[3]);
	philo->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->repetition = ft_atoi(argv[5]);
	if ((philo->philo < 2 || philo->die <= 0 || philo->eat <= 0 || \
	philo->sleep <= 0) || (argc == 6 && philo->repetition <= 0))
	{
		write(1, "Invalid input\n", 15);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo *philo;

	if (!(philo = malloc(sizeof(t_philo))))
		return (-1);
	if (validate_input(argc, argv, philo) == -1)
	{
		free(philo);
		return (-1);
	}
	printf("%d\n", philo->eat);
	system("leaks philo_one");
	return (0);
}
