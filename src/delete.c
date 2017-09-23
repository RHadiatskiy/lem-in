/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:50:22 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/25 20:50:24 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

void				delete_split(char **split)
{
	int			i;

	i = 0;
	if (split)
	{
		while (split[i])
			free(split[i++]);
		free(split);
	}
}

void				delete_temp_data(t_temp_data *data)
{
	if (data)
	{
		if (data->name)
			free(data->name);
		if (data->key)
			free(data->key);
		free(data);
	}
}
