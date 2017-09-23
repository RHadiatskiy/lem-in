/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_some_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 21:29:52 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/29 22:29:54 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

int					check_dublicate_coord(t_rooms *rooms, int x, int y)
{
	t_rooms		*temp;

	temp = rooms;
	if (temp->name)
	{
		while (temp)
		{
			if (temp->x_coord == x && temp->y_coord == y)
				return (0);
			temp = temp->next;
		}
	}
	return (1);
}

int					check_to_match(t_rooms *rooms, char *name1, char *name2)
{
	int			match_name_1;
	int			match_name_2;
	t_rooms		*tmp;

	tmp = rooms;
	match_name_1 = 0;
	match_name_2 = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name1) == 0)
			match_name_1++;
		else if (ft_strcmp(tmp->name, name2) == 0)
			match_name_2++;
		tmp = tmp->next;
	}
	if ((match_name_1 == 0 || match_name_2 == 0) && \
		ft_strcmp(name1, name2) != 0)
		return (0);
	return (1);
}

int					check_to_dublicate_link(t_links *link, char *name)
{
	char		*n;

	if (link->room)
	{
		n = name;
		while (link)
		{
			if (ft_strcmp(link->room->name, n) == 0)
				return (0);
			link = link->next;
		}
	}
	return (1);
}

int					check_dublicate_names(t_rooms *rooms, char *name)
{
	t_rooms		*tmp_rooms;

	tmp_rooms = rooms;
	if (tmp_rooms->name)
	{
		while (tmp_rooms)
		{
			if (ft_strcmp(tmp_rooms->name, name) == 0)
				return (0);
			tmp_rooms = tmp_rooms->next;
		}
	}
	return (1);
}

int					check_identification(t_rooms *rooms)
{
	t_rooms		*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (tmp->is_end == 1 && tmp->id == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
