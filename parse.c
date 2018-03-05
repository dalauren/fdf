/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:55:09 by vpoccard          #+#    #+#             */
/*   Updated: 2018/03/03 15:15:19 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_get_nb(t_mlx *mlx, char *line)
{
	int			i;

	i = 0;
	mlx->tab = ft_strsplit(line, ' ');
	while (mlx->tab[i] != '\0')
		i++;
	if (mlx->nbl == 0)
	{
		mlx->nbc1 = i;
		mlx->nbc = i;
	}
	if (mlx->nbc != i)
		return (-1);
	mlx->nbl += 1;
	return (0);
}

int				ft_tab(t_mlx *mlx)
{
	char		*line;
	int			ret;

	mlx->nbl = 0;
	mlx->nbc = 0;
	while ((ret = get_next_line(mlx->fd, &line)) > 0)
	{
		if (ft_get_nb(mlx, line) == -1)
			return (-1);
		free(line);
	}
	close(mlx->fd);
	mlx->map = ft_memalloc(mlx->nbl);
	return (0);
}

void			free_me(int **map, int max_i)
{
	int			i;

	i = 0;
	while (i < max_i)
	{
		free(map[i]);
		i++;
	}
}

int				ft_parse(t_mlx *mlx, char **argv)
{
	t_splitint	s;

	s.i = 0;
	s.j = 0;
	if (ft_tab(mlx) == -1)
		return (-1);
	mlx->fd = open(argv[1], O_RDONLY);
	while ((s.ret = get_next_line(mlx->fd, &s.line)) > 0)
	{
		s.j = 0;
		s.tab = ft_strsplit(s.line, ' ');
		mlx->map[s.i] = ft_memalloc(sizeof(int) * mlx->nbc);
		while (s.tab[s.j] != NULL)
		{
			mlx->map[s.i][s.j] = ft_atoi(s.tab[s.j]);
			s.j++;
		}
		free(s.tab);
		free(s.line);
		s.i++;
	}
	mlx->imax = s.i;
	close(mlx->fd);
	return (0);
}
