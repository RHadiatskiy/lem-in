/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 18:52:52 by rhadiats          #+#    #+#             */
/*   Updated: 2017/09/08 18:52:57 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

static void				set_id_for_start_room(t_rooms *rooms)
{
	t_rooms		*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (tmp->is_start == 1)
			tmp->id = 1;
		tmp = tmp->next;
	}
}

t_rooms					*get_start_room(t_rooms *rooms)
{
	t_rooms		*start;

	start = rooms;
	while (start)
	{
		if (start->is_start == 1)
			break ;
		start = start->next;
	}
	return (start);
}

static t_rooms			*get_end_room(t_rooms *rooms)
{
	t_rooms		*end;

	end = rooms;
	while (end)
	{
		if (end->is_end == 1)
			break ;
		end = end->next;
	}
	return (end);
}

static void				setting(t_rooms *rooms)
{
	t_rooms		*tmp_rooms;
	t_rooms		*set;
	t_links		*tmp_links;

	tmp_rooms = rooms;
	while (tmp_rooms)
	{
		tmp_links = tmp_rooms->link;
		while (tmp_links)
		{
			if (tmp_links->room)
			{
				set = get_room_pointer(rooms, tmp_links->room->name);
				if (set->id == 0)
					set->id = tmp_rooms->id > 0 ? tmp_rooms->id + 1 : 0;
			}
			tmp_links = tmp_links->next;
		}
		tmp_rooms = tmp_rooms->next;
	}
}

void					set_id(t_rooms *rooms)
{
	int			iter;
	t_rooms		*end;

	iter = 0;
	end = get_end_room(rooms);
	set_id_for_start_room(rooms);
	while (iter++ < get_room_list_size(rooms) && end->id == 0)
		setting(rooms);
}
