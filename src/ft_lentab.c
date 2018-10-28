/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lentab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:09:30 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/05 19:05:01 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		intlen(int *i)
{
	int		j;

	j = 0;
	while (i[j])
		j++;
	return (j);
}

int		listlen(t_room *begin)
{
	int		i;

	i = 0;
	while (begin)
	{
		begin = begin->next;
		i++;
	}
	return (i);
}

int		len_room(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

int		len_tube(char *str, char *tmp)
{
	return (ft_strlen(str) - (ft_strlen(tmp) + 1));
}
