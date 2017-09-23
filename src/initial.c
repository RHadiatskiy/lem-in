/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 20:30:48 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/23 20:30:49 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

void				reset_valid_struct(t_valid *valid)
{
	valid->start = 0;
	valid->end = 0;
	valid->links = 0;
	valid->is_ants = 0;
	valid->ants = 0;
}

t_temp_data			*initial_temp_data(char *name, int x, int y, char *key)
{
	t_temp_data	*data;

	if (!(data = (t_temp_data *)malloc(sizeof(t_temp_data))))
		return (NULL);
	data->name = name;
	data->x = x;
	data->y = y;
	data->key = key;
	return (data);
}

t_links				*initial_links_list(void)
{
	t_links		*links;

	if (!(links = (t_links *)malloc(sizeof(t_links))))
		return (NULL);
	links->room = NULL;
	links->next = NULL;
	return (links);
}

t_rooms				*initial_rooms_list(void)
{
	t_rooms		*rooms;

	if (!(rooms = (t_rooms *)malloc(sizeof(t_rooms))))
		return (NULL);
	rooms->init = 0;
	rooms->id = 0;
	rooms->name = NULL;
	rooms->x_coord = 0;
	rooms->y_coord = 0;
	rooms->is_empty = 0;
	rooms->is_start = 0;
	rooms->is_end = 0;
	rooms->link = initial_links_list();
	rooms->next = NULL;
	return (rooms);
}

t_to_print			*initial_to_print(void)
{
	t_to_print	*to_print;

	if (!(to_print = (t_to_print *)malloc(sizeof(t_to_print))))
		return (NULL);
	to_print->text = NULL;
	to_print->path = NULL;
	return (to_print);
}
