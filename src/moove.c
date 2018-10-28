/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:31:22 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/06 13:45:51 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	moove(t_room *begin, t_room *end, char **str)
{
	t_room	*list;
	t_room	*tmp;

	list = begin;
	tmp = begin;
	while (list)
	{
		if (list->ants > 0)
		{
			while (tmp)
			{
				if (moove_end(list, end, tmp, str) == 0)
					break ;
				if (tmp->i > list->i && room_cmp(list->tube, \
				tmp->name) == 0 && tmp->ants > 0 && list->ants > 0)
				{
					list = tmp;
					tmp = begin->next;
				}
				tmp = tmp->next;
			}
		}
		tmp = begin;
		list = list->next;
	}
}

int		moove_end(t_room *list, t_room *end, t_room *tmp, char **str)
{
	if (room_cmp(list->tube, tmp->name) == 0 && tmp->i == list->i + 1)
	{
		if (room_cmp(list->tube, end->name) == 0)
			tmp = end_room(end);
		if (ft_strcmp(tmp->property, "##end") == 0)
		{
			init_str(list->ants, tmp->name, &str[0]);
			tmp->ants += 1;
			list->ants = 0;
			return (0);
		}
		else if (tmp->ants == 0)
		{
			tmp->ants = list->ants;
			init_str(tmp->ants, tmp->name, &str[0]);
			list->ants = 0;
			return (0);
		}
	}
	return (1);
}

void	moove_start(t_room *begin, int *i, char **str)
{
	t_room	*list;

	list = begin;
	while (list)
	{
		if (room_cmp(begin->tube, list->name) == 0 && \
		begin->i + 1 == list->i && begin->ants > 0)
		{
			if (ft_strcmp(list->property, "##end") == 0)
			{
				init_str(i[intlen(i) - begin->ants], list->name, &str[0]);
				list->ants += 1;
				begin->ants -= 1;
			}
			else if (list->ants == 0)
			{
				init_str(i[intlen(i) - begin->ants], list->name, &str[0]);
				list->ants = i[intlen(i) - begin->ants];
				begin->ants -= 1;
			}
		}
		list = list->next;
	}
}

void	moove_ants(t_room *begin, t_room *end)
{
	int		j;
	char	*str;
	int		*t;

	str = ft_strnew(500);
	end->ants = 0;
	t = init_ant(begin->ants);
	while (end->ants != intlen(t))
	{
		j = end->ants;
		while (j < intlen(t) && end->ants != intlen(t))
		{
			moove(begin->next, end, &str);
			if (begin->ants > 0)
				moove_start(begin, t, &str);
			j++;
		}
	}
	ft_memdel((void**)&t);
	ft_putstr(str);
	ft_strdel(&str);
}
