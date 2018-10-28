/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:45:56 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/06 13:37:40 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*init_ant(int nb)
{
	int		*i;
	int		j;

	j = 0;
	if (!(i = (int*)malloc(sizeof(int) * (nb + 2))))
		return (NULL);
	while (j < (nb))
	{
		if (j == 0)
			i[j] = 1;
		else
			i[j] = i[j - 1] + 1;
		j++;
	}
	i[j] = 0;
	return (i);
}

t_room	init_start(t_room begin, char **str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	begin.name = ft_strnew(len_room(*str));
	begin.name = ft_strncpy(begin.name, *str, len_room(*str));
	while (str[0][i])
	{
		if (i + j < (int)ft_strlen(str[0]) && str[0][i + j] == ' ')
			j++;
		if (i > 0 && str[0][(i + j) - 1] == ' ')
		{
			if (j == 1)
				begin.x = ft_atoi(str[0] + (i + j));
			if (j == 2)
				begin.y = ft_atoi(str[0] + (i + j));
		}
		i++;
	}
	return (begin);
}

void	init_str(int ant, char *room, char **str)
{
	char	*s;
	int		len;

	s = ft_itoa(ant);
	len = (ft_strlen(str[0]) + ft_strlen(room) + ft_strlen(s) + 7);
	if ((check_str(str, s) == 0) && ft_strlen(str[0]) > 0)
		str[0][ft_strlen(str[0])] = '\n';
	else if ((check_str(str, s) == 1) && ft_strlen(str[0]) > 0)
		str[0][ft_strlen(str[0])] = ' ';
	if (len >= 480)
	{
		ft_putstr(str[0]);
		ft_bzero(str[0], ft_strlen(str[0]));
	}
	str[0][ft_strlen(str[0])] = 'L';
	ft_strcat(str[0], s);
	str[0][ft_strlen(str[0])] = '-';
	ft_strcat(str[0], room);
	ft_strdel(&s);
}

int		check_str(char **str, char *s)
{
	int		i;
	int		j;

	if (ft_strlen(str[0]) > 0)
		j = ft_strlen(str[0]) - 1;
	else
		return (-1);
	while (str[0][j] != '\n' && j != 0)
	{
		i = 0;
		if (s[i] == str[0][j] && str[0][j - 1] == 'L')
		{
			while (s[i] && s[i] == str[0][j + i])
			{
				if (s[i + 1] == '\0')
					return (0);
				i++;
			}
		}
		j--;
	}
	return (1);
}
