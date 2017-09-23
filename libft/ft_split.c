/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 15:15:56 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/10 15:15:58 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_words(const char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		else if ((s[i] != ' ' && s[i] != '\t' && s[i] != '\n') && \
				(s[i + 1] == ' ' || s[i + 1] == '\t' || \
				s[i + 1] == '\n' || s[i + 1] == '\0'))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

char	**allocate_tab(char **dst, const char *s)
{
	int		i;
	int		j;
	int		w;

	i = 0;
	j = 0;
	while (s[i])
	{
		w = 0;
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
			i++;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i])
		{
			w++;
			i++;
		}
		if (w != 0)
			dst[j] = (char *)malloc(sizeof(char) * w + 1);
		else if (w == 0)
			dst[j] = (char *)malloc(sizeof(char) + 1);
		dst[j][w] = '\0';
		j++;
	}
	return (dst);
}

char	**put_tab(char **dst, const char *s)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	l = 0;
	while (s[l])
	{
		j = 0;
		while ((s[l] == ' ' || s[l] == '\t' || s[l] == '\n') && s[l])
			l++;
		while (s[l] != ' ' && s[l] != '\t' && s[l] != '\n' && s[l])
			dst[i][j++] = s[l++];
		i++;
	}
	return (dst);
}

char	**ft_split(const char *s)
{
	char	**tab;
	int		len;

	len = count_words(s);
	if (!(tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	tab = allocate_tab(tab, s);
	tab = put_tab(tab, s);
	tab[len] = NULL;
	return (tab);
}
