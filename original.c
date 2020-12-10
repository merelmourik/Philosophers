/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 13:19:24 by mmourik       #+#    #+#                 */
/*   Updated: 2020/11/30 14:21:08 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_dup(char *str)
{
	int		i;
	char	*new;
	
	i = 0;
	while (str[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return(NULL);
	i = 0;
	while (str[i])
	{
		 new[i] = str[i];
		 i++;
	}
	new[i] = '\0';
	return (new);
}

int		ft_chr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return(i);
		i++;
	}
	return (-1);
}

char	*ft_sub(char *str, int i, int j)
{
	char *new;
	int k;

	if (j == 1)
	{
		new = malloc(sizeof(char) * (i + 1));
		if (!new)
			return (NULL);
		k = 0;
		while (k < i)
		{
			new[k] = str[k];
			k++;
		}
		new[k] = '\0';
	}
	if (j == 2)
	{
		while (str[k])
			k++;
		new = malloc(sizeof(char) * (k - i));
		if (!new)
			return (NULL);
		i++;			// over de \n springen
		k = 0;
		while (str[i + k])
		{
			new[k] = str[i + k];
			k++;
		}
		new[k] = '\0';
		free(str);
	}
	return(new);
}

char	*ft_join(char *str1, char *str2)
{
	int		i = 0;
	int		j = 0;
	char	*new;
	
	while(str1[i])
		i++;
	while(str2[j])
		j++;
	new = malloc(sizeof(char) * (i + j + 1));
	if (new == NULL)
		return(NULL);
	i = 0;
	while (str1[i])
	{
		new[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		new[i + j] = str2[j];
		j++;
	}
	new[i + j] = '\0';
	free (str1);		//str freeen als hetgeen na de \n ook is doorgegeven
	return (new);
}

int	get_next_line(char **line)
{
	static char	*str;
	char		*buffer;
	char		*temp;
	int			ret;
	int			i;

	if (!line || read(0, NULL, 0) == -1)
		return (-1);
	if (!str)
		str = ft_dup("");
	if (str == NULL)
		return (-1);
	i = ft_chr(str);		//i de positie  van de new line
	if (i >= 0)				//de eerste keer gaat hij deze loop dus niet in
	{
		*line = ft_sub(str, i, 1);		//line vullen met de string tot \n
		if (!line)
			return (-1);
		str = ft_sub(str, i, 2);		//str vullen met het gedeelte van de string na \n 
		if (!str)						//zodat we bij de volgende call weten waar we waren in str(static)
			return (-1);
		return (1);						//functie returnen zodat die weer verder de loop in gaat
	}
	ret = 1;
	while (ret)
	{
		buffer = malloc(sizeof(char) * 128);
		if (!buffer)
			return(-1);
		ret = read(0, buffer, 127);	//alles inlezen in buffer
		buffer[ret] = '\0';			//zorgen dat de buffer NULL terminated is
		i = ft_chr(buffer);			//kijken of er een newline staat in buffer
		if (i == -1)				//er staat geen newline in bufffer
		{
			str = ft_join(str, buffer);	//str en buffer aan elkaar plakken
			free (buffer);
			if (!str)
				return (-1);
		}
		if (i >= 0)			//er staat wel een new line in buffer
		{
			temp = ft_sub(buffer, i, 1);		//temp vullen met de buffer tot \n
			if (temp == NULL)
				return(-1);
			*line = ft_join(str, temp);			//line en temp aan elkaar plakken
			free (temp);
			if (!line)
				return(-1);
			str = ft_sub(buffer, i, 2);			//er voor zorgen dat str gevuld is met het gedeelte van de buffer na \n
			if (!str)
				return(-1);
			return (1);			//returnen zodat hij weer door gaat loopen
		}
	}
	*line = ft_dup(str);		//checken of er niet nog wat restjes in str zitten, als dit zo is vullen in line
	free (str);
	if (!line)
		return (-1);
	return(0);
}
