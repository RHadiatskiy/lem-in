/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 16:11:44 by rhadiats          #+#    #+#             */
/*   Updated: 2017/09/14 16:11:58 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

int					get_id(t_rooms *rooms, char *name)
{
	t_rooms		*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			break ;
		tmp = tmp->next;
	}
	return (tmp->id);
}

void				finding_path(t_to_print *to_print, t_rooms *rooms)
{
	t_rooms		*tmp_rooms;
	t_links		*tmp_links;

	tmp_rooms = rooms;
	if (tmp_rooms->is_start == 0)
	{
		tmp_links = tmp_rooms->link;
		while (tmp_links)
		{
			if (tmp_links->room->id + 1 == tmp_rooms->id)
			{
				finding_path(to_print, tmp_links->room);
				if (to_print->path)
				{
					if (check_to_dublicate_link(to_print->path, tmp_links->room->name))
						path_list_added(&to_print->path, tmp_links->room);
				}
				else
					path_list_added(&to_print->path, tmp_links->room);
			}
			tmp_links = tmp_links->next;
		}
	}
	if (tmp_rooms->is_end == 1)
		path_list_added(&to_print->path, tmp_rooms);
}

