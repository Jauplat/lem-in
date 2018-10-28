/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:17:05 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/06 13:37:12 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	algo(t_room *begin)
{
	t_room	*end;
	t_room	*list;

	list = begin;
	end = begin;
	end = end_room(begin);
	lstadd_end(&list, end);
	check_param(begin, end);
	moove_ants(begin, end);
}
