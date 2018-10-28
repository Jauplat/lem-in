/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 12:44:47 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/05 19:01:29 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	same_name(t_room *begin, char *str)
{
	if (!begin->tube)
	{
		begin->tube = ft_strnew(len_tube(str, begin->name));
		begin->tube = ft_strncpy(begin->tube, \
		str + (ft_strlen(begin->name) + 1), len_tube(str, begin->name));
	}
	else
	{
		begin->tube = join_free(begin->tube, " ");
		begin->tube = njoin_free(begin->tube, \
		str + (ft_strlen(begin->name) + 1), len_tube(str, begin->name));
	}
}

void	second_name(t_room *begin, char *str)
{
	if (!begin->tube)
	{
		begin->tube = ft_strnew(len_tube(str, begin->name));
		begin->tube = ft_strncpy(begin->tube, str, len_tube(str, begin->name));
	}
	else
	{
		begin->tube = join_free(begin->tube, " ");
		begin->tube = njoin_free(begin->tube, str, len_tube(str, begin->name));
	}
}

void	add_tube(char *str, t_room *room)
{
	t_room	*begin;

	begin = room;
	while (begin)
	{
		if (ft_strstr(str, begin->name) == str + (len_tube(str, begin->name) \
		+ 1) && str[len_tube(str, begin->name)] == '-')
			second_name(begin, str);
		else if (ft_strstr(str, begin->name) == str && \
		str[ft_strlen(begin->name)] == '-')
			same_name(begin, str);
		begin = begin->next;
	}
}

int		check_tube(char *str, t_room *room)
{
	char	*tmp;
	t_room	*begin;

	tmp = NULL;
	begin = room;
	if (ft_strcmp(begin->property, "##start") == 0 && begin->next == NULL)
		error(-3);
	while (begin)
	{
		if ((tmp = ft_strstr(str, begin->name)) == str)
		{
			if (str[ft_strlen(begin->name)] != '-')
				return (-1);
		}
		else if (ft_strstr(str, begin->name) == str + \
		(len_tube(str, begin->name) + 1))
		{
			if (str[len_tube(str, begin->name)] != '-')
				return (-1);
		}
		begin = begin->next;
	}
	return (0);
}
