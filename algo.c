/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:25:34 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/24 20:00:22 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	to_isometri(t_point ***pt, t_mlx *mlx, int i, int j)
{
	t_line l;

	l.p1.x = pt[i][j]->x - pt[i][j]->y;
	l.p1.y = pt[i][j]->z * mlx->scale / mlx->div
		+ 0.5 * pt[i][j]->x + 0.5 * pt[i][j]->y;
	l.p1.z = pt[i][j]->z * -1;
	return (l.p1);
}

static int		chose_color(t_mlx *mlx, int i, int j)
{
	if (mlx->pt[i][j]->z == 0)
		mlx->color = 0x007575;
	else
		mlx->color = 0x00FFFF;
	return (mlx->color);
}

static void		get_draw_line(t_point ***pt, int i, int j, t_mlx *mlx)
{
	t_line		l;

	l.p1 = to_isometri(pt, mlx, i, j);
	mlx->color = chose_color(mlx, i, j);
	if (j + 1 < mlx->size_line)
	{
		l.p2 = to_isometri(pt, mlx, i, j + 1);
		line(l, mlx, mlx->color);
	}
	mlx->color = chose_color(mlx, i, j);
	if (i + 1 < mlx->nb_line)
	{
		l.p2 = to_isometri(pt, mlx, i + 1, j);
		line(l, mlx, mlx->color);
	}
}

int				draw_map(t_mlx *mlx)
{
	int			i;
	int			j;
	t_point		***pt;

	pt = mlx->pt;
	i = 0;
	while (i < mlx->nb_line)
	{
		j = 0;
		while (j < mlx->size_line)
		{
			get_draw_line(pt, i, j, mlx);
			j++;
		}
		i++;
	}
	return (1);
}
