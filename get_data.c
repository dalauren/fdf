/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:31:43 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/09 18:13:01 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_lstdelete(t_parse *parse)
{
	t_list		*tmp;
	char		**tmp_content;

	while (parse->lst)
	{
		tmp_content = (char **)parse->lst->content;
		ft_deltab(tmp_content);
		tmp = parse->lst;
		parse->lst = parse->lst->next;
		free(tmp);
	}
}

void			free_pt(t_point ****pt)
{
	int		i;
	int		j;

	i = 0;
	while((*pt)[i])
	{
		j = 0;
		while((*pt)[i][j])
		{
			free((*pt)[i][j]);
			j++;
		}
		free((*pt)[i]);
		i++;
	}
	free(*(pt));
}

static int		get_pos(t_parse *parse, t_mlx *mlx)
{
	int		i;
	int		j;
	t_list	*tmp;
	char	**tmp2;

	i = 0;
	tmp = parse->lst;
	if (!(mlx->pt = (t_point ***)malloc(sizeof(t_point **) * (parse->nb_line + 1))))
		return (-1);
	while (i < parse->nb_line)
	{
		if (!(mlx->pt[i] = (t_point **)malloc(sizeof(t_point *) *
						(parse->len_previous + 1))))
			return (-1);
		j = 0;
		while (j < parse->len_previous)
		{
			if (!(mlx->pt[i][j] = (t_point *)malloc(sizeof(t_point))))
				return (-1);
			mlx->pt[i][j]->x = i;
			mlx->pt[i][j]->y = j;
			tmp2 = (char **)(tmp->content);
			mlx->pt[i][j]->z = ft_atoi(tmp2[j]);
			j++;
		}
		mlx->pt[i][j] = 0;
		tmp = tmp->next;
		i++;
	}
	mlx->pt[i] = 0;
	printf("after = %p\n", mlx->pt);
	return (0);
}

int				get_data(t_parse *parse, t_mlx *mlx)
{
	if ((get_pos(parse, mlx)) < 0)
		return (-1);
	return (0);
}
