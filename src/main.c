/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:49:08 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/23 19:49:10 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

t_links		*ft_sort_list(t_links *path)
{
	t_links		*tmp1;
	t_links		*tmp2;
	t_rooms		*ret;

	ret = NULL;
	tmp1 = path;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->room->id > tmp2->room->id)
			{
				ret = tmp1->room;
				tmp1->room = tmp2->room;
				tmp2->room = ret;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (path);
}


int			main(void)
{
	t_valid		valid;
	t_rooms		*rooms;
	t_rooms		*end_rooms;
	t_to_print	*to_print;

	to_print = initial_to_print();
	rooms = initial_rooms_list();
	reset_valid_struct(&valid);
	to_print->text = ft_strnew(0);
	if (!valid_and_parsing(rooms, &valid, to_print))
		return (error_message(0));
	set_id(rooms);
	if (!check_identification(rooms))
		return (error_message(0));
	write(1, to_print->text, (int)ft_strlen(to_print->text));
	print_rooms_list(rooms);
	print_debug_valid(&valid);
	end_rooms = get_room_pointer(rooms, get_end_room_name(rooms));
	finding_path(to_print, end_rooms);
	to_print->path = ft_sort_list(to_print->path);
	print_path_list(to_print->path);
	return (0);
}
