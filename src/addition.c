/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c.                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:10:14 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/29 15:10:16 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

void				rooms_first_added(t_rooms *rooms, t_temp_data *data)
{
	if (rooms->init == 0)
	{
		rooms->id = 0;
		rooms->name = data->name;
		rooms->init = rooms->init + 1;
		rooms->x_coord = data->x;
		rooms->y_coord = data->y;
		rooms->is_empty = 0;
		rooms->is_start = (ft_strcmp(data->key, "start") == 0) ? 1 : 0;
		rooms->is_end = (ft_strcmp(data->key, "end") == 0) ? 1 : 0;
		rooms->link = initial_links_list();
		rooms->next = NULL;
	}
}

void				rooms_list_added(t_rooms *rooms, t_temp_data *data)
{
	t_rooms		*temp;

	if (rooms->init == 0)
		rooms_first_added(rooms, data);
	else if ((temp = (t_rooms *)malloc(sizeof(t_rooms))))
	{
		while (rooms->next)
			rooms = rooms->next;
		temp->id = 0;
		temp->name = data->name;
		temp->x_coord = data->x;
		temp->y_coord = data->y;
		temp->is_empty = 0;
		temp->is_start = (ft_strcmp(data->key, "start") == 0) ? 1 : 0;
		temp->is_end = (ft_strcmp(data->key, "end") == 0) ? 1 : 0;
		temp->link = initial_links_list();
		temp->next = NULL;
		rooms->next = temp;
	}
	free(data);
}

void				links_list_added(t_links *links, t_rooms *room)
{
	t_links		*temp;

	if (links->init == 0)
	{
		links->init = links->init + 1;
		links->room = room;
		links->next = NULL;
	}
	else if ((temp = (t_links *)malloc(sizeof(t_links))))
	{
		while (links->next)
			links = links->next;
		temp->room = room;
		temp->next = NULL;
		links->next = temp;
	}
}

void				path_list_added(t_links **path, t_rooms *room)
{
	t_links		*temp;

	if ((temp = (t_links *)malloc(sizeof(t_links))))
	{
		temp->room = room;
		temp->next = (*path);
		(*path) = temp;
	}
}
