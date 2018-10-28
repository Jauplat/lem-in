/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:38:47 by jauplat           #+#    #+#             */
/*   Updated: 2018/06/06 13:14:33 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct	s_room
{
	char			*name;
	char			*property;
	int				ants;
	int				x;
	int				y;
	int				i;
	char			*tube;
	struct s_room	*next;
}				t_room;

int				main(void);
t_room			*init_room(void);
void			error(int n);
void			parse(t_room *room);
t_room			*parse2(char **str, t_room *room, int n);

int				ant(char **str);
int				check_ants(char *str);
int				check_line(char *str);

void			property(char **str, int *n, t_room **begin, t_room **room);
int				property_srch(t_room *begin, char **str, char *stmp);
t_room			init_start(t_room begin, char **str);
void			no_room(t_room *begin);

t_room			*add_room(char *str, char **tmp);
int				len_room(char *str);
int				check_room(char *str);
t_room			*end_room(t_room *begin);

t_room			*lstnew(char *content, char *property);
void			lstadd_end(t_room **alst, t_room *new);
void			lstdel(t_room **alst);
void			lstdelone(t_room **alst);
int				listlen(t_room *begin);

void			link_room(char **str, t_room *room);
int				len_tube(char *str, char *tmp);
void			add_tube(char *str, t_room *room);
int				check_tube(char *str, t_room *room);
void			seconde_name(t_room *begin, char *str);
void			same_name(t_room *begin, char *str);

void			algo(t_room *begin);

void			check_param(t_room *begin, t_room *end);
void			param_room(t_room *begin, int i);
void			init_param(t_room *list, t_room *tmp, int i);
int				*init_ant(int nb);

void			moove_ants(t_room *begin, t_room *end);
void			moove_start(t_room *begin, int *i, char **str);
void			moove(t_room *begin, t_room *end, char **str);
int				moove_end(t_room *list, t_room *end, t_room *tmp, char **str);
int				room_cmp(char *s1, char *s2);
int				intlen(int *i);

int				check_str(char **str, char *s);
void			init_str(int ant, char *room, char **str);
void			ft_putlist(t_room *room);

#endif
