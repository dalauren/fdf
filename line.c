/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:01:23 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/20 16:22:49 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init(t_point *cur, t_point *d, t_line l)
{
	cur->x = l.p1.x;
	cur->y = l.p1.y;
	d->x = (l.p2.x - l.p1.x) < 0 ? -(l.p2.x - l.p1.x) : (l.p2.x - l.p1.x);
	d->y = (l.p2.y - l.p1.y) < 0 ? -(l.p2.y - l.p1.y) : (l.p2.y - l.p1.y);
}

static void	line_inc(t_line line, t_point *cur, int swp, int step)
{
	if (step >= 0)
	{
		if (swp)
			cur->x += (line.p2.x - line.p1.x) < 0 ? -1 : 1;
		else
			cur->y += (line.p2.y - line.p1.y) < 0 ? -1 : 1;
	}
	else
	{
		if (swp)
			cur->y += (line.p2.y - line.p1.y) < 0 ? -1 : 1;
		else
			cur->x += (line.p2.x - line.p1.x) < 0 ? -1 : 1;
	}
}

void		line(t_line l, t_mlx *mlx, int color)
{
	t_point	cur;
	t_point	d;
	int		swp;
	int		step;
	int		i;

	init(&cur, &d, l);
	swp = (d.y > d.x);
	if (swp)
		ft_swap(&d.x, &d.y);
	i = 0;
	step = 2 * d.y - d.x;
	while (++i <= d.x)
	{
		// faire un put pixel qui prend en compte le Z
		mlx_pixel_put(mlx->ptr, mlx->win, cur.x + (mlx->size_w / 2),
				cur.y + (mlx->size_h / 2), color);
		if (step >= 0)
		{
			line_inc(l, &cur, swp, step);
			step -= 2 * d.x;
		}
		line_inc(l, &cur, swp, step);
		step += 2 * d.y;
	}
}
