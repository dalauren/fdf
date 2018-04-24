/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:31:43 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/24 20:11:07 by dalauren         ###   ########.fr       */
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
	while ((*pt)[i])
	{
		j = 0;
		while ((*pt)[i][j])
		{
			free((*pt)[i][j]);
			j++;
		}
		free((*pt)[i]);
		i++;
	}
	free(*(pt));
}

void			transform_point(t_mlx *mlx)
{
	int		i;
	int		j;

	if (mlx->size_line > mlx->nb_line)
		mlx->scale = SIZE_W / (mlx->size_line * 2);
	else if (mlx->z_scale > mlx->nb_line)
		mlx->scale = SIZE_H / mlx->z_scale * 2;
	else
		mlx->scale = SIZE_H / (mlx->nb_line * 2);
	i = 0;
	while (i < mlx->nb_line)
	{
		j = 0;
		while (j < mlx->size_line)
		{
			mlx->pt[i][j]->x = j * mlx->scale;
			mlx->pt[i][j]->y = i * mlx->scale;
			j++;
		}
		i++;
	}
}

static int		get_pos(t_parse *parse, t_mlx *mlx)
{
	int		i;
	int		j;
	t_list	*tmp;
	char	**tmp2;

	i = 0;
	tmp = parse->lst;
	if (!(mlx->pt = (t_point ***)malloc(sizeof(t_point **) *
					(parse->nb_line + 1))))
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
			mlx->pt[i][j]->x = j * mlx->scale;
			mlx->pt[i][j]->y = i * mlx->scale;
			tmp2 = (char **)(tmp->content);
			mlx->pt[i][j]->z = ft_atoi(tmp2[j]);
			get_z(mlx->pt[i][j]->z, mlx);
			mlx->pt[i][j]->z *= -1;
			j++;
		}
		mlx->pt[i][j] = 0;
		tmp = tmp->next;
		i++;
	}
	mlx->pt[i] = 0;
	return (0);
}

int				get_data(t_parse *parse, t_mlx *mlx)
{
	if ((get_pos(parse, mlx)) < 0)
		return (-1);
	return (0);
}
