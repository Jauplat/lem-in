/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:50:03 by jauplat           #+#    #+#             */
/*   Updated: 2018/07/07 10:29:27 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*init_room(void)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	room->name = NULL;
	room->property = NULL;
	room->ants = 0;
	room->x = 0;
	room->y = 0;
	room->i = 0;
	room->tube = NULL;
	room->next = NULL;
	return (room);
}

int		main(void)
{
	t_room	*room;
	char	*str;

	str = NULL;
	room = init_room();
	parse(room);
	algo(room);
	lstdel(&room);
	return (0);
}
