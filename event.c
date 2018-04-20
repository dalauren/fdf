/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 11:24:33 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/20 16:54:01 by dalauren         ###   ########.fr       */
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
	mlx_clear_window(mlx->ptr, mlx->win);
	start_map(mlx);
}

void	modif_height(int key, t_mlx *mlx)
{
	if (key == KEY_Z)
		mlx->div += 0.2;
	if (key == KEY_X)
		mlx->div -= 0.2;
	mlx_clear_window(mlx->ptr, mlx->win);
	start_map(mlx);
}

int		ft_mouse(int button, int x, int y, void *param)
{
	/*t_point pt[3][3];*/
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (1);
}

int		ft_keyboard(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->ptr,mlx->win);
		ft_putstr("program closed successfully.\n");
		exit(EXIT_SUCCESS);
	}
	if (key == KEY_Z || key == KEY_X)
		modif_height(key, mlx);
	if (key <= KEY_UARROW && key >= KEY_LARROW )
		modif_place(key, mlx);
	return (0);
}

