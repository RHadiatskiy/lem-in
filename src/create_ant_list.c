/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ant_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 18:05:15 by rhadiats          #+#    #+#             */
/*   Updated: 2017/09/22 18:05:16 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

t_ant_list			*initial_ant_list(void)
{
	t_ant_list		*ant_list;

	if (!(ant_list = (t_ant_list *)malloc(sizeof(t_ant_list))))
		return (NULL);
	ant_list->init = 0;
	ant_list->id = 0;
	ant_list->room = NULL;
	ant_list->next = NULL;
	return (ant_list);
}

void				ant_list_added(t_ant_list *ant, int id, t_rooms *room)
{
	t_ant_list	*tmp;

	if (ant->init == 0)
	{
		ant->init = ant->init + 1;
		ant->id = id;
		ant->room = room;
		ant->next = NULL;
	}
	else if ((tmp = (t_ant_list *)malloc(sizeof(t_ant_list))))
	{
		while (ant->next)
			ant = ant->next;
		tmp->id = id;
		tmp->room = room;
		tmp->next = NULL;
		ant->next = tmp;
	}
}

void				setting_ant_list(t_ant_list *ant_list, int ant_count, \
	t_rooms *rooms)
{
	int			id;
	t_rooms		*ptr_room;

	id = 1;
	ptr_room = get_room_pointer(rooms, get_start_room_name(rooms));
	while (id <= ant_count)
		ant_list_added(ant_list, id++, ptr_room);
}

void				print_ant_list(t_ant_list *ant)
{
	t_ant_list	*tmp;

	tmp = ant;
	ft_printf("%s--------------ANTS--------------%s\n", CYAN, RESET);
	while (tmp)
	{
		ft_printf("ID: \t\t\t%d\n", tmp->id);
		ft_printf("ROOM: \t\t\t%s\n", tmp->room->name);
		tmp = tmp->next;
		ft_printf("%s---------------------------------%s\n", CYAN, RESET);
	}
}