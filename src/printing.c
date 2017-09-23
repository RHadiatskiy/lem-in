/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 20:30:30 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/23 20:30:32 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

void				print_debug_valid(t_valid *valid)
{
	ft_printf("%s--------------DEBUG--------------%s\n", RED, RESET);
	ft_printf("%sSTART : \t\t\t%u%s\n", RED, valid->start, RESET);
	ft_printf("%sEND : \t\t\t\t%u%s\n", RED, valid->end, RESET);
	ft_printf("%sLINKS : \t\t\t%u%s\n", RED, valid->links, RESET);
	ft_printf("%sIS ANTS : \t\t\t%u%s\n", RED, valid->is_ants, RESET);
	ft_printf("%sANTS : \t\t\t\t%u%s\n", RED, valid->ants, RESET);
	ft_printf("%s---------------------------------%s\n", RED, RESET);
}

void				print_temp_data(t_temp_data *data)
{
	if (data)
	{
		ft_printf("--------------DATA--------------\n");
		ft_printf("data name : %s\n", data->name);
		ft_printf("data x : %d\n", data->x);
		ft_printf("data y : %d\n", data->y);
		ft_printf("data key : %s\n", data->key);
	}
}

void				print_rooms_list(t_rooms *rooms)
{
	t_rooms		*tmp;

	tmp = rooms;
	ft_printf("%s--------------ROOMS--------------%s\n", GREEN, RESET);
	while (tmp)
	{
		if (tmp->is_start == 1)
			ft_printf("\t\t%sStart room%s\n", CYAN, RESET);
		else if (tmp->is_end == 1)
			ft_printf("\t\t%sEnd room%s\n", CYAN, RESET);
		ft_printf("ID : \t\t\t\t%s%d%s\n", YELLOW, tmp->id, RESET);
		ft_printf("NAME : \t\t\t\t%s%s%s\n", GREEN, tmp->name, RESET);
		ft_printf("X : \t\t\t\t%d\n", tmp->x_coord);
		ft_printf("Y : \t\t\t\t%d\n", tmp->y_coord);
		if (tmp->link)
			print_links_list(tmp->link);
		ft_printf("%s---------------------------------%s\n", GREEN, RESET);
		tmp = tmp->next;
	}
}

void				print_links_list(t_links *links)
{
	t_links		*tmp;

	tmp = links;
	while (tmp)
	{
		ft_printf("LINK [id] : %d\t\t%s\n", tmp->room->id, tmp->room->name);
		tmp = tmp->next;
	}
}

void				print_path_list(t_links *path)
{
	t_links		*tmp;

	tmp = path;
	if (path)
	{
		if (tmp->next)
			print_path_list(tmp->next);
		ft_printf("PATH : \t%s\t\tid : %d\t\tstatus : %s\n", tmp->room->name,
			tmp->room->id, tmp->room->is_empty ? "occupied" : "empty");
	}
}
