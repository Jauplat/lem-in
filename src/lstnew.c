/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:58:13 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/05 19:09:22 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*lstnew(char *content, char *property)
{
	t_room	*list;

	if (!(list = malloc(sizeof(t_room))))
		return (NULL);
	if (content == NULL)
		list->name = NULL;
	else
	{
		list->name = ft_strnew(len_room(content));
		list->name = ft_strncpy(list->name, content, len_room(content));
	}
	((property) ? (list->property = ft_strdup(property)) \
	: (list->property = NULL));
	list->ants = 0;
	list->tube = NULL;
	list->x = 0;
	list->y = 0;
	list->i = 0;
	list->next = NULL;
	return (list);
}

void	lstadd_end(t_room **alst, t_room *end)
{
	while ((*alst)->next != end)
		(*alst) = (*alst)->next;
	(*alst)->next = end->next;
	while ((*alst)->next)
		(*alst) = (*alst)->next;
	(*alst)->next = end;
	end->next = NULL;
}

void	lstdel(t_room **alst)
{
	t_room	*tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		lstdelone(alst);
		*alst = tmp;
	}
}

void	lstdelone(t_room **alst)
{
	ft_memdel((void **)&(*alst)->name);
	ft_memdel((void **)&(*alst)->property);
	ft_memdel((void **)&(*alst)->tube);
	ft_memdel((void **)alst);
}
