/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:16:44 by vpoccard          #+#    #+#             */
/*   Updated: 2018/02/27 04:18:16 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_menu(void)
{
	ft_putchar('\n');
	ft_putendl("Q = zoom");
	ft_putendl("W = -zoom");
	ft_putendl("esc = kill window");
	ft_putendl("clear = Clear window");
	ft_putendl("return = Draw again");
	ft_putendl("moove with the arrow");
	ft_putendl("A = +relief");
	ft_putendl("S = -relief");
	ft_putchar('\n');
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;
	int		i;

	i = 0;
	if (ft_or(argc, argv, &mlx) != 1)
		return (-1);
	if (ft_parse(&mlx, argv) == -1)
	{
		ft_putendl("fdf cant run correctly");
		return (-1);
	}
	ft_menu();
	ft_init_mlx(&mlx);
	return (0);
}
