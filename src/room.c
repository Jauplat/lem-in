/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:17:25 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/05 19:01:46 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*add_room(char *str, char **tmp)
{
	int		i;
	int		j;
	t_room	*list;

	i = 0;
	j = 0;
	list = lstnew(str, *tmp);
	while (str[i])
	{
		if (j == 1 && ft_isdigit(str[i]) && (str[i - 1] == ' ' || \
			(str[i - 1] == '+' && str[i - 2] == ' ')))
			list->x = ft_atoi(str + i);
		if (j == 2 && ft_isdigit(str[i]) && (str[i - 1] == ' ' || \
			(str[i - 1] == '+' && str[i - 2] == ' ')))
			list->y = ft_atoi(str + i);
		if (str[i] == ' ')
			j++;
		i++;
	}
	return (list);
}

int		check_room(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strchr(str, ' ') == NULL)
		return (0);
	while ((str[i + j] || j < 2) && str[0] != '#' && str[0] != 'L')
	{
		if (i == 0)
		{
			while (ft_isprint(str[i]))
				i++;
		}
		if (str[i + j] == ' ' && (ft_isdigit(str[i + j + 1])))
			j++;
		i++;
		if (!(str[i + j]) && j != 2)
			return (0);
	}
	if (j != 2)
		return (0);
	return (1);
}
