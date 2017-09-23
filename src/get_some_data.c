/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_some_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 20:29:52 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/29 20:29:54 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

int					get_room_list_size(t_rooms *rooms)
{
	int			size;
	t_rooms		*tmp;

	size = 0;
	tmp = rooms;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

char				*get_start_room_name(t_rooms *rooms)
{
	t_rooms		*tmp;
	char		*name;

	name = NULL;
	tmp = rooms;
	while (tmp)
	{
		if (tmp->is_start == 1)
			name = ft_strdup(tmp->name);
		tmp = tmp->next;
	}
	return (name);
}

char				*get_end_room_name(t_rooms *rooms)
{
	t_rooms		*tmp;
	char		*name;

	name = NULL;
	tmp = rooms;
	while (tmp)
	{
		if (tmp->is_end == 1)
			name = ft_strdup(tmp->name);
		tmp = tmp->next;
	}
	return (name);
}

int					get_num_split(char **split)
{
	int			num;

	num = 0;
	if (split)
	{
		while (split[num])
			num++;
	}
	return (num);
}

t_rooms				*get_room_pointer(t_rooms *rooms, char *name)
{
	t_rooms		*tmp;

	tmp = rooms;
	while (rooms)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
