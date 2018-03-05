/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:53:12 by vpoccard          #+#    #+#             */
/*   Updated: 2018/02/27 03:36:24 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_abs(int i)
{
	if (i == 0)
		return (i);
	if (i < 0)
		return (-i);
	if (i > 0)
		return (i);
	return (0);
}

static void		ft_bresenham(t_mlx *mlx, t_xayaxbyb *ab, int xb, int yb)
{
	t_bresenham	b;

	b.i = ft_abs(ab->xa - xb);
	b.j = ft_abs(ab->ya - yb);
	b.k = xb < ab->xa ? 1 : -1;
	b.l = yb < ab->ya ? 1 : -1;
	b.m = (b.i > b.j ? b.i : -b.i) / 2;
	while (xb != ab->xa || yb != ab->ya)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, xb, yb, mlx->color);
		b.n = b.m;
		b.n > -b.i ? b.m -= b.j : 1 == 1;
		b.n > -b.i ? xb += b.k : 1 == 1;
		b.n < b.j ? b.m += b.i : 1 == 1;
		b.n < b.j ? yb += b.l : 1 == 1;
	}
}

void			ft_map_line(t_mlx *mlx, int x, int y)
{
	t_xayaxbyb	ab;

	ab.nxtx = x / mlx->sx;
	ab.nxty = y / mlx->sy;
	ab.xa = mlx->dx + ((x + mlx->sx) - y);
	ab.ya = mlx->dy + (x + mlx->sx) + y +
		mlx->map[ab.nxty][ab.nxtx + 1] * mlx->z;
	ab.xb = mlx->dx + (x - y);
	ab.yb = mlx->dy + mlx->map[y / mlx->sy][x / mlx->sx] * mlx->z + x + y;
	ft_color(mlx, ab.nxty, ab.nxtx);
	if ((ab.nxtx < mlx->nbc - 1) && (ab.nxty < mlx->nbl))
		ft_bresenham(mlx, &ab, ab.xb, ab.yb);
	ab.xa = mlx->dx + (x - (y + mlx->sy));
	if (ab.nxty < mlx->nbl - 1 && ab.nxtx < mlx->nbc)
	{
		ab.ya = mlx->dy + mlx->map[ab.nxty += 1][ab.nxtx]
				* mlx->z + x + (y + mlx->sy);
		ft_bresenham(mlx, &ab, ab.xb, ab.yb);
	}
}
