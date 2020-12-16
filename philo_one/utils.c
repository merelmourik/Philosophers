/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 09:41:52 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/12/16 12:42:21 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnumber(unsigned long n)
{
	if (n > 9)
	{
		ft_putnumber(n / 10);
		ft_putnumber(n % 10);
	}
	if (n < 10)
		ft_putchar(n + 48);
}

int		ft_usleep(int64_t wait_time)
{
	int64_t	start;

	start = time_stamp();
	if (start == -1)
		return (-1);
	while ((time_stamp() - start) < wait_time)
		usleep(100);
	return (0);
}

int			ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	if (res == 0)
		return (0);
	return (res * sign);
}