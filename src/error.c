/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:47:06 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/05 18:59:22 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(int n)
{
	ft_putchar('\n');
	if (n == -2)
		ft_putendl("Bad character for ants number");
	else if (n == -3)
		ft_putendl("No room or room only");
	else if (n == -4)
		ft_putendl("Double start or double end");
	else if (n == -5)
		ft_putendl("Not valid path");
	else if (n == -6)
		ft_putendl("Not start or no end");
	else if (n < 0)
		ft_putendl("ERROR");
	exit(0);
}
