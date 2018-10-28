/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:02:12 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/11 17:45:38 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ant(char **str)
{
	int		i;

	i = 0;
	while ((i = check_line(str[0])) <= 0)
	{
		if (i == -1)
			error(-2);
		ft_strdel(&str[0]);
		if ((i = get_next_line(0, &str[0])) <= 0)
			error(-2);
		ft_putendl(str[0]);
	}
	if (check_ants(str[0]) == 0)
		error(-2);
	return (ft_atoi(str[0]));
}

int		check_line(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp(str, "##start") == 0 || ft_strcmp(str, "##end") == 0)
		return (-1);
	if (str[0] == '#')
		return (0);
	return (1);
}

int		check_ants(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[j] == '0')
		j++;
	if (!str[j])
		return (0);
	if (str[0] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
		i++;
	if (str[i])
		return (0);
	return (1);
}
