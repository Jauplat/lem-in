/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:43:34 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/05 18:59:31 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*end_room(t_room *begin)
{
	t_room	*end;

	end = begin;
	while (end && (ft_strcmp(end->property, "##end")) != 0)
		end = end->next;
	return (end);
}
