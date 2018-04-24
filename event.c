/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 11:24:33 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/24 20:01:39 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	modif_place(int key, t_mlx *mlx)
{
	if (key == KEY_UARROW)
		mlx->size_h -= 20;
	else if (key == KEY_DARROW)
		mlx->size_h += 20;
	else if (key == KEY_LARROW)
		mlx->size_w -= 20;
	else if (key == KEY_RARROW)
		mlx->size_w += 20;
	mlx_destroy_image(mlx->ptr, mlx->img.img_ptr);
	start_map(mlx);
}

void	ft_zoom(int key, t_mlx *mlx)
{
	if (key == KEY_PLUS)
		zoom_plus(mlx);
	else if (key == KEY_LESS)
		zoom_less(mlx);
	mlx_destroy_image(mlx->ptr, mlx->img.img_ptr);
	start_map(mlx);
}

void	modif_height(int key, t_mlx *mlx)
{
	if (key == KEY_Z && mlx->div < 35)
		mlx->div += 0.2;
	else if (key == KEY_X && mlx->div > 1)
		mlx->div -= 0.2;
	mlx_destroy_image(mlx->ptr, mlx->img.img_ptr);
	start_map(mlx);
}

int		ft_keyboard(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		ft_putstr("program closed successfully.\n");
		exit(EXIT_SUCCESS);
	}
	else if (key == KEY_RETURN)
		reset_map(mlx);
	else if (key == KEY_Z || key == KEY_X)
		modif_height(key, mlx);
	else if (key <= KEY_UARROW && key >= KEY_LARROW)
		modif_place(key, mlx);
	else if (key == KEY_PLUS || key == KEY_LESS)
		ft_zoom(key, mlx);
	return (0);
}
