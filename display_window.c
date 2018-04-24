/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:33:19 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/24 20:06:38 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			start_map(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->ptr, mlx->size_w, mlx->size_h);
	mlx->img.img_str = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
			&mlx->img.s_l, &mlx->img.endian);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	mlx_hook(mlx->win, 2, 3, ft_keyboard, mlx);
	mlx_loop(mlx->ptr);
	return (1);
}

void		put_pixel(int x, int y, unsigned int color, t_img *img)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	b = (color & 0xFF) >> 0;
	g = (color & 0xFF00) >> 8;
	r = (color & 0xFF0000) >> 16;
	if (img->endian == 0)
	{
		if (img->img_str[(y * img->s_l) + x * (img->bpp / 8)] != b)
			img->img_str[(y * img->s_l) + x * (img->bpp / 8)] = b;
		if (img->img_str[(y * img->s_l) + x * (img->bpp / 8) + 1] != g)
			img->img_str[(y * img->s_l) + x * (img->bpp / 8) + 1] = g;
		if (img->img_str[(y * img->s_l) + x * (img->bpp / 8) + 2] != r)
			img->img_str[(y * img->s_l) + x * (img->bpp / 8) + 2] = r;
	}
	else
	{
		img->img_str[y * img->s_l + x * img->bpp / 8] = (color & 0xFF) >> 0;
		img->img_str[y * img->s_l + x * img->bpp / 8 + 1] =
			(color & 0xFF00) >> 8;
		img->img_str[y * img->s_l + x * img->bpp / 8 + 2] =
			(color & 0xFF0000) >> 16;
	}
}

void		get_z(int z, t_mlx *mlx)
{
	if (z > mlx->z_max)
		mlx->z_max = z;
	if (z < mlx->z_min)
		mlx->z_min = z;
}
