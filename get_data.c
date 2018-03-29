/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:31:43 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/29 14:51:39 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_pos(t_parse *parse, t_point ***pt)
{
	int		i;
	int		j;
	t_list	*tmp;
	char	**tmp2;

	i = 0;
	j = 0;
	tmp = parse->lst;
	if (!(pt = (t_point ***)malloc(sizeof(t_point **) * parse->nb_line)))
		return (-1);
	while (i < parse->nb_line)
	{
		if (!(pt[i] = (t_point **)malloc(sizeof(t_point *) *
						parse->len_previous)))
			return (-1);
		while (j < parse->len_previous)
		{
			if (!(pt[i][j] = (t_point *)malloc(sizeof(t_point))))
				return (-1);
			pt[i][j]->x = i;
			pt[i][j]->y = j;
			tmp2 = (char **)(tmp->content);
			pt[i][j]->z = ft_atoi(tmp2[j]);
			j++;
		}
		j = 0;
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int				get_data(t_parse *parse)
{
	t_point		**pt;

	ft_bzero(&pt, sizeof(pt));
	if ((get_pos(parse, &pt)) < 0)
		return (-1);
	return (0);
}// pas oublier de free le tab a la fin
