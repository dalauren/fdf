/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:33:19 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/10 19:04:58 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			start_map(t_mlx *mlx)
{
	mlx->img.pt_image = mlx_new_image(mlx->ptr, SIZE_W, SIZE_H);
	mlx->img.data = (int*)mlx_get_data_addr(mlx->img.pt_image, &mlx->img.bpp,
			&mlx->img.size_l, &mlx->img.endian);
	mlx_key_hook(mlx->win, ft_keyboard, mlx);
	mlx_loop(mlx->ptr);
	return (1);
}

//l'endian sert a savoir le sens de lecture d'un octet
//petit endian = faible->fort (0 -> 124)
//grand->endian = fort->faible (124 -> 0)
//
//a la fin faire mlx_put_img_to_window pour afficher la map
