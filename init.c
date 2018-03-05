/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:19:01 by vpoccard          #+#    #+#             */
/*   Updated: 2018/02/27 04:11:39 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_init_fdf(t_mlx *mlx)
{
	mlx->z = -5;
	mlx->sx = (WIDTH * 0.4) / mlx->nbc1;
	mlx->sy = (HEIGHT * 0.25) / mlx->nbl;
	mlx->dx = WIDTH * 0.4;
	mlx->dy = HEIGHT * 0.05;
	mlx->color = 0xFFFFFF;
	return (0);
}

void			ft_fdf(t_mlx *mlx)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	ft_init_fdf(mlx);
	while (x / mlx->sx < mlx->nbc || y / mlx->sy < mlx->nbl - 1)
	{
		if (x / mlx->sx == mlx->nbc)
		{
			x = 0;
			y += mlx->sy;
		}
		ft_map_line(mlx, x, y);
		x += mlx->sx;
	}
}

void			ft_fdf_key(t_mlx *mlx)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (x / mlx->sx < mlx->nbc || y / mlx->sy < mlx->nbl - 1)
	{
		if (x / mlx->sx == mlx->nbc)
		{
			x = 0;
			y += mlx->sy;
		}
		ft_map_line(mlx, x, y);
		x += mlx->sx;
	}
}

int				ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if ((mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1500, 1500,
					"Windows fdf")) == NULL)
		return (-1);
	mlx_key_hook(mlx->win_ptr, ft_keyboard, mlx);
	ft_fdf(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (1);
}
