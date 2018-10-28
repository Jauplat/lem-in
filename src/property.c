/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   property.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:55:03 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/05 19:01:40 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	property(char **str, int *n, t_room **begin, t_room **room)
{
	char	*tmp;
	int		i;

	tmp = ft_strdup(str[0]);
	ft_strdel(&str[0]);
	((i = get_next_line(0, &str[0])) <= 0) ? error(-3) : NULL;
	if (property_srch(*begin, &str[0], tmp) != 0)
		error(-4);
	if (ft_strcmp(tmp, "##start") == 0 && n[0] > 0)
	{
		**begin = init_start(**begin, &str[0]);
		(*begin)->property = ft_strdup(tmp);
		n[0] = n[0] - 1;
	}
	else if (ft_strcmp(tmp, "##end") == 0 && n[0] > 0)
	{
		(*room)->next = add_room(str[0], &tmp);
		(*room) = (*room)->next;
		n[0] = n[0] - 1;
	}
	ft_putendl(str[0]);
	ft_strdel(&str[0]);
	ft_strdel(&tmp);
}

int		property_srch(t_room *begin, char **str, char *stmp)
{
	t_room	*tmp;
	int		i;

	tmp = begin;
	while ((i = check_line(str[0])) == 0)
	{
		ft_putendl(str[0]);
		ft_strdel(&str[0]);
		((i = get_next_line(0, &str[0])) <= 0) ? error(-3) : NULL;
		if (ft_strcmp(str[0], stmp) == 0 && (!ft_strcmp(stmp, "##start") \
		|| !ft_strcmp(stmp, "##end")))
			return (1);
	}
	while (tmp)
	{
		if (ft_strcmp(tmp->property, stmp) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
