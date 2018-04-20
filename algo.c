/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:25:34 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/20 15:11:54 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point		to_isometri(t_point ***pt, t_mlx *mlx, int i, int j)
{
	t_line l;

	l.p1.x = pt[i][j]->x - pt[i][j]->y;
	l.p1.y = pt[i][j]->z * mlx->scale / mlx->div
		+ 0.5 * pt[i][j]->x + 0.5 * pt[i][j]->y;
	return (l.p1);
}

static int		chose_color(t_mlx *mlx, int i, int j, t_point ***pt)
{
	if (pt[i][j]->z == 0)
		mlx->color = 0xFF7777;
	else if (pt[i][j]->z == 0 && (pt[i][j + 1]->z > 0 || pt[i + 1][j]->z > 0))
		mlx->color = 0x221144; // marche pas
	else
		mlx->color = 0xFFFFFF;
	return (mlx->color);
}

static void		get_draw_line(t_point ***pt, int i, int j, t_mlx *mlx)
{
	t_line		l;

	l.p1 = to_isometri(pt, mlx, i, j);
	mlx->color = chose_color(mlx, i, j, pt);
	if (j + 1 < mlx->size_line)
	{
		l.p2 = to_isometri(pt, mlx, i, j + 1);
		line(l, mlx, mlx->color);
	}
	mlx->color = chose_color(mlx, i, j, pt);
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
			get_draw_line(pt, i , j, mlx);
			j++;
		}
		i++;
	}
	return (1);
}
