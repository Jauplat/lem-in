/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:18:32 by jauplat           #+#    #+#             */
/*   Updated: 2018/07/07 10:41:03 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse(t_room *room)
{
	char		*str;
	int			n;

	str = NULL;
	n = ant(&str);
	ft_strdel(&str);
	room->ants = n;
	parse2(&str, room, n);
	no_room(room);
	link_room(&str, room);
	ft_putchar('\n');
	ft_strdel(&str);
}

void	no_room(t_room *begin)
{
	t_room	*list;
	int		i;
	int		j;

	j = 0;
	i = 0;
	list = begin;
	while (list)
	{
		list = list->next;
		i++;
	}
	list = end_room(begin);
	if (i < 2)
		error(-3);
	if (ft_strcmp(begin->property, "##start") || list == NULL)
		error(-6);
}

t_room	*parse2(char **str, t_room *room, int n)
{
	static char	*tmp;
	int			r;
	t_room		*begin;

	begin = room;
	n = 2;
	while ((r = get_next_line(0, &str[0])) > 0)
	{
		ft_putendl(*str);
		if (str[0][0] == '#' && ft_strcmp(str[0], "##start") != 0 \
		&& ft_strcmp(str[0], "##end") != 0)
			ft_strdel(&str[0]);
		else if (str[0][0] == '#')
			property(&str[0], &n, &begin, &room);
		else if (check_room(*str))
		{
			room->next = add_room(*str, &tmp);
			room = room->next;
		}
		else
			break ;
		ft_strdel(&str[0]);
	}
	return (begin);
}

void	link_room(char **str, t_room *room)
{
	int		r;

	r = 0;
	add_tube(*str, room);
	ft_strdel(&str[0]);
	while ((r = get_next_line(0, &str[0])) > 0)
	{
		ft_putendl(*str);
		add_tube(*str, room);
		ft_strdel(&str[0]);
	}
}
