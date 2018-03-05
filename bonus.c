/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:53:46 by vpoccard          #+#    #+#             */
/*   Updated: 2018/03/03 15:09:09 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int				ft_color(t_mlx *mlx, int nxty, int nxtx)
{
	if ((mlx->map[nxty][nxtx] * mlx->z) <= -200)
		mlx->color = 0x032667;
	if ((mlx->map[nxty][nxtx] * mlx->z) > -200 &&
			(mlx->map[nxty][nxtx] * mlx->z) <= -50)
		mlx->color = 0x04358F;
	if ((mlx->map[nxty][nxtx] * mlx->z) > -50 &&
			(mlx->map[nxty][nxtx] * mlx->z) < 0)
		mlx->color = 0x206BF8;
	if ((mlx->map[nxty][nxtx] * mlx->z) == 0)
		mlx->color = 0x508CFA;
	if ((mlx->map[nxty][nxtx] * mlx->z) > 0 &&
			(mlx->map[nxty][nxtx] * mlx->z) < 50)
		mlx->color = 0x29E6F3;
	if ((mlx->map[nxty][nxtx] * mlx->z) >= 50 &&
			(mlx->map[nxty][nxtx] * mlx->z) < 200)
		mlx->color = 0xC8DAFD;
	if ((mlx->map[nxty][nxtx] * mlx->z) >= 200)
		mlx->color = 0xE1EBFE;
	return (0);
}

static	void	ft_moove(int key, t_mlx *mlx)
{
	if (key >= KEY_LARROW && key <= KEY_UARROW)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if (key == KEY_LARROW)
			mlx->dx -= 15;
		if (key == KEY_UARROW)
			mlx->dy -= 15;
		if (key == KEY_RARROW)
			mlx->dx += 15;
		if (key == KEY_DARROW)
			mlx->dy += 15;
		ft_fdf_key(mlx);
	}
}

static	void	ft_zoom(int key, t_mlx *mlx)
{
	if (key == KEY_Q && mlx->sy < 3000)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->sy = mlx->sy * 2;
		mlx->z = mlx->z * 2;
		mlx->sx = mlx->sx * 2;
		ft_fdf_key(mlx);
	}
	if (key == KEY_W && mlx->sy > 1)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->sy = mlx->sy / 2;
		mlx->z = mlx->z / 2;
		mlx->sx = mlx->sx / 2;
		ft_fdf_key(mlx);
	}
}

static	void	ft_altitude(int key, t_mlx *mlx)
{
	if (key == KEY_A)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->z != 0)
			mlx->z = mlx->z * 2;
		else
			mlx->z = -5;
		ft_fdf_key(mlx);
	}
	if (key == KEY_S)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->z = mlx->z / 2;
		ft_fdf_key(mlx);
	}
}

int				ft_keyboard(int key, t_mlx *mlx)
{
	ft_altitude(key, mlx);
	ft_moove(key, mlx);
	ft_zoom(key, mlx);
	if (key == KEY_RETURN)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_fdf(mlx);
	}
	if (key == KEY_ESC)
	{
		free_me(mlx->map, mlx->imax);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	}
	if (key == KEY_CLEAR)
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	return (0);
}
