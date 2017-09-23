/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 20:29:52 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/23 20:29:54 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

int					valid_start_end_links(t_rooms *rooms)
{
	char		*start_name;
	char		*end_name;

	start_name = get_start_room_name(rooms);
	end_name = get_end_room_name(rooms);
	if (!is_start_is_end_loop(rooms, start_name, end_name))
	{
		free(start_name);
		free(end_name);
		return (0);
	}
	free(start_name);
	free(end_name);
	return (1);
}

int					valid_start_line(t_valid *valid, t_rooms *rooms, \
	char **split, char *line)
{
	int			num;
	char		*name;
	t_temp_data	*data;

	num = get_num_split(split);
	if (split[0])
		name = ft_strdup(split[0]);
	if (num == 3 && count_symbol(line, ' ') == 2 && split[0][0] != 'L' && \
		split[0][0] != '#' && ft_strisdigit(split[1]) && valid->links == 0 \
		&& ft_strisdigit(split[2]) && (valid->start == 0) && \
		check_dublicate_names(rooms, name) && ft_strcmp(line, "##end"))
	{
		valid->start = 1;
		data = initial_temp_data(name, ft_atoi(split[1]), \
			ft_atoi(split[2]), "start");
		rooms_list_added(rooms, data);
	}
	else
		return (0);
	return (1);
}

int					valid_end_line(t_valid *valid, t_rooms *rooms, \
	char **split, char *line)
{
	int			num;
	char		*name;
	t_temp_data	*data;

	num = get_num_split(split);
	if (split[0])
		name = ft_strdup(split[0]);
	if (num == 3 && count_symbol(line, ' ') == 2 && split[0][0] != 'L' && \
		split[0][0] != '#' && ft_strisdigit(split[1]) && valid->links == 0 \
		&& ft_strisdigit(split[2]) && (valid->end == 0) && \
		check_dublicate_names(rooms, name) && ft_strcmp(line, "##start"))
	{
		valid->end = 1;
		data = initial_temp_data(name, ft_atoi(split[1]), \
			ft_atoi(split[2]), "end");
		rooms_list_added(rooms, data);
	}
	else
		return (0);
	return (1);
}

int					valid_links(t_valid *valid, t_rooms *rooms, char *line)
{
	int			num;
	char		**split;
	char		*name1;
	char		*name2;

	if (!rooms->name)
		return (0);
	split = ft_strsplit(line, '-');
	num = get_num_split(split);
	name1 = ft_strdup(split[0]);
	name2 = ft_strdup(split[1]);
	if (count_symbol(line, '-') == 1 && num == 2 && \
		check_to_match(rooms, name1, name2))
	{
		parse_links(rooms, name1, name2);
		valid->links = 1;
	}
	else
	{
		free(name1);
		free(name2);
		return (0);
	}
	delete_split(split);
	return (1);
}

int					valid_and_parsing(t_rooms *rooms, t_valid *valid, \
	t_to_print *to_print)
{
	char		*line;

	line = NULL;
	if (!parse_ants(valid, line, to_print))
		return (0);
	while (get_next_line(0, &line))
	{
		writing_text_file_valid_loop(line, to_print);
		if (!switch_route_of_parse(rooms, valid, line, to_print))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	if (valid->start == 0 || valid->end == 0 || valid->is_ants == 0 || \
		valid->links == 0 || valid->ants == 0 || !valid_start_end_links(rooms))
		return (0);
	return (1);
}
