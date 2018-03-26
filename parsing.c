/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:25:42 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/26 14:08:38 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strtablen(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_check_tab(t_parse *parse)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = 0;
	while (parse->tab[i])
	{
		while (parse->tab[i][j])
		{
			if (parse->tab[i][j] == '-')
				j++;
			if (!ft_isdigit(parse->tab[i][j]) && parse->tab[i][j] != '-')
				return (-1);
			while (ft_isdigit(parse->tab[i][j]) && parse->tab[i][j])
				j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
