/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:47:07 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/06 13:02:57 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_order(t_room *begin)
{
	t_room	*list;

	list = begin;
	while (list)
	{
		if (list->i == 0)
			return (0);
		list = list->next;
	}
	return (1);
}

int		ft_min(t_room *begin)
{
	int		j;
	t_room	*list;

	j = 0;
	list = begin;
	while (list)
	{
		if (ft_strstr(begin->tube, list->name) != NULL)
		{
			if (list->i == 0 && j == 0)
				j = 0;
			else if (j == 0)
				j = (list->i - 1);
			else if ((list->i - 1) < j)
				j = (list->i - 1);
		}
		list = list->next;
	}
	return (j);
}

void	param_room(t_room *begin, int i)
{
	t_room		*list;
	t_room		*tmp;

	list = begin;
	tmp = begin;
	while (list && begin->i == 0)
	{
		if (list->i == (i + 1))
		{
			while (tmp && begin->i == 0)
			{
				if (room_cmp(list->tube, tmp->name) == 0 && tmp->i < list->i)
					tmp->i = i;
				tmp = tmp->next;
			}
		}
		tmp = begin;
		list = list->next;
	}
}

void	check_param(t_room *begin, t_room *end)
{
	int		i;

	i = listlen(begin);
	end->i = i;
	if (end->tube == NULL)
		error(-5);
	while (begin->i == 0 && i)
	{
		i--;
		param_room(begin, i);
	}
	if (begin->i == 0)
		error(-5);
}
