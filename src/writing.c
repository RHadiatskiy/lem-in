/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 17:53:00 by rhadiats          #+#    #+#             */
/*   Updated: 2017/09/16 17:53:06 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

void				writing_text_file(char *line, t_to_print *to_print)
{
	char		*tmp1;
	char		*tmp2;

	tmp1 = ft_strjoin(line, "\n");
	tmp2 = to_print->text;
	to_print->text = ft_strjoin(to_print->text, tmp1);
	free(tmp1);
	free(tmp2);
	free(line);
}

void				writing_text_file_valid_loop(char *line, \
	t_to_print *to_print)
{
	char		*tmp1;
	char		*tmp2;

	tmp1 = ft_strjoin(line, "\n");
	tmp2 = to_print->text;
	to_print->text = ft_strjoin(to_print->text, tmp1);
	free(tmp1);
	free(tmp2);
}
