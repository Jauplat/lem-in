/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:24:10 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/05 19:01:01 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_path(t_room *begin, t_room *end)
{
	t_room	*list;
	t_room	*tmp;

	list = begin;
	tmp = begin;
	if (end->tube == NULL)
		error(-5);
	end->i = 1;
}
