/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 19:50:22 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/25 19:50:24 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

int				parse_start(t_valid *valid, t_rooms *rooms, char *line, \
	t_to_print *to_print)
{
	char		**split;

	if (!ft_strcmp(line, "##start"))
	{
		while (get_next_line(0, &line) && line[0] == '#' && \
			ft_strcmp(line, "##end"))
			writing_text_file(line, to_print);
		split = ft_strsplit(line, ' ');
		if (!valid_start_line(valid, rooms, split, line))
		{
			delete_split(split);
			return (0);
		}
		writing_text_file(line, to_print);
		delete_split(split);
	}
	return (1);
}

int				parse_end(t_valid *valid, t_rooms *rooms, char *line, \
	t_to_print *to_print)
{
	char		**split;

	if (!ft_strcmp(line, "##end"))
	{
		while (get_next_line(0, &line) && line[0] == '#' && \
			ft_strcmp(line, "##start"))
			writing_text_file(line, to_print);
		split = ft_strsplit(line, ' ');
		if (!valid_end_line(valid, rooms, split, line))
		{
			delete_split(split);
			return (0);
		}
		writing_text_file(line, to_print);
		delete_split(split);
	}
	return (1);
}

int				parse_room(t_valid *valid, t_rooms *rooms, char *line)
{
	char		**split;
	int			num;
	t_temp_data	*data;

	data = NULL;
	split = ft_strsplit(line, ' ');
	num = get_num_split(split);
	if (num == 3 && count_symbol(line, ' ') == 2 && split[0][0] != 'L' && \
		split[0][0] != '#' && ft_strisdigit(split[1]) && \
		ft_strisdigit(split[2]) && check_dublicate_coord(rooms, \
			ft_atoi(split[1]), ft_atoi(split[2])) && valid->links == 0 && \
		check_dublicate_names(rooms, split[0]))
	{
		data = initial_temp_data(ft_strdup(split[0]), \
				ft_atoi(split[1]), ft_atoi(split[2]), "none");
		rooms_list_added(rooms, data);
	}
	else
	{
		delete_split(split);
		return (0);
	}
	delete_split(split);
	return (1);
}

void			parse_links(t_rooms *rooms, char *name1, char *name2)
{
	t_rooms		*tmp_rooms;
	t_links		*tmp_links;

	tmp_rooms = rooms;
	while (tmp_rooms)
	{
		tmp_links = tmp_rooms->link;
		if (ft_strcmp(tmp_rooms->name, name1) == 0)
		{
			if (check_to_dublicate_link(tmp_links, name2))
				links_list_added(tmp_links, get_room_pointer(rooms, name2));
		}
		else if (ft_strcmp(tmp_rooms->name, name2) == 0)
		{
			if (check_to_dublicate_link(tmp_links, name1))
				links_list_added(tmp_links, get_room_pointer(rooms, name1));
		}
		tmp_rooms = tmp_rooms->next;
	}
	free(name1);
	free(name2);
}

int				parse_ants(t_valid *valid, char *line, t_to_print *to_print)
{
	while (get_next_line(0, &line) && line[0] == '#' && \
		(ft_strcmp(line, "") != 0) && line[0] != 'L')
		writing_text_file(line, to_print);
	if (!ft_strisdigit(line))
	{
		free(line);
		return (0);
	}
	valid->is_ants = 1;
	valid->ants = ft_atoi(line);
	writing_text_file(line, to_print);
	return (1);
}
