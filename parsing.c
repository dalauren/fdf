/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:25:42 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/24 19:56:29 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t			ft_strtablen(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void			ft_display_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		i++;
	}
}

int				ft_check_tab(t_parse *parse)
{
	int i;
	int j;
	int len;

	i = 0;
	len = 0;
	while (parse->tab[i])
	{
		j = 0;
		while (parse->tab[i][j])
		{
			while (parse->tab[i][j] && ft_isdigit(parse->tab[i][j]))
				j++;
			if (parse->tab[i][j] == '-')
				j++;
			if ((!ft_isdigit(parse->tab[i][j]) && parse->tab[i][j] == '-'))
				return (-1);
			if (parse->tab[i][j])
				j++;
		}
		i++;
	}
	return (1);
}
