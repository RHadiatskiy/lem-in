/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 19:52:22 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/25 19:52:26 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

int					count_symbol(char *line, char symbol)
{
	int			counter;

	counter = 0;
	while (*line)
		if (*line++ == symbol)
			counter++;
	return (counter);
}

int					error_message(int number)
{
	if (number == 0)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	return (1);
}

int					identify_line(char *line)
{
	int			i;

	i = 0;
	if (line[0] == '#')
		return (1);
	while (line[i] != ' ' && line[i] != '-' && line[i])
		i++;
	if (line[i] == ' ')
		return (2);
	else if (line[i] == '-')
		return (3);
	return (0);
}

int					switch_route_of_parse(t_rooms *rooms, t_valid *valid, \
	char *line, t_to_print *to_print)
{
	if ((ft_strcmp(line, "") != 0 && line[0] != 'L') || line[0] == '#')
	{
		if (identify_line(line) == 1)
		{
			if (!parse_start(valid, rooms, line, to_print) || \
				!parse_end(valid, rooms, line, to_print))
				return (0);
		}
		else if (identify_line(line) == 2)
		{
			if (!parse_room(valid, rooms, line))
				return (0);
		}
		else if (identify_line(line) == 3)
		{
			if (!valid_links(valid, rooms, line))
				return (0);
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int					is_start_is_end_loop(t_rooms *rooms, char *start_name, \
	char *end_name)
{
	t_rooms		*tmp;
	t_links		*links;
	int			match_start;
	int			match_end;

	tmp = rooms;
	match_start = 0;
	match_end = 0;
	while (tmp)
	{
		links = tmp->link;
		while (links)
		{
			if (links->room && ft_strcmp(links->room->name, start_name) == 0)
				match_start++;
			else if (links->room && ft_strcmp(links->room->name, end_name) == 0)
				match_end++;
			links = links->next;
		}
		tmp = tmp->next;
	}
	if (match_start == 0 || match_end == 0)
		return (0);
	return (1);
}
