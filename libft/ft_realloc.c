/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 13:19:50 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/03 13:46:21 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(char *ptr, size_t size)
{
	char	*newptr;

	if (!size || !ptr)
	{
		newptr = ft_strnew(1);
		return (newptr);
	}
	newptr = ft_strnew(size + 1);
	if (ptr)
	{
		ft_memcpy(newptr, ptr, size - 1);
		ft_memdel((void *)&ptr);
	}
	return (newptr);
}
