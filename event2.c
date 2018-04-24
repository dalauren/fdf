/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:42:03 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/24 18:41:37 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_map(t_mlx *mlx)
{
	mlx->div = 5;
	mlx_destroy_window(mlx->ptr, mlx->win);
	ft_open_file(mlx, mlx->format);
	ft_init_mlx(mlx);
}
