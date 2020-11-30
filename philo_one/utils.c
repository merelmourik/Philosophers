/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 09:41:52 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/11/30 10:28:11 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	ft_atoi(const char *str)
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

unsigned long	time_stamp(void)
{
	struct timeval	current;
	unsigned long	stamp;

	gettimeofday(&current, NULL);
	stamp = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (stamp);
}

char	*long_to_str(unsigned long value)
{
	unsigned long	tmp;
	int				count;
	char			*str;

	tmp = value;
	count = 0;
	if (tmp == 0)
		count++;
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	if (!(str = malloc(sizeof(char) * count)))
		return (NULL);
	str[count] = '\0';
	count--;
	while (count >= 0)
	{
		str[count] = value % 10 + '0';
		value /= 10;
		count--;
	}
	return (str);
}

