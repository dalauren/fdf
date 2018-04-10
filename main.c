/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:59:52 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/10 15:49:05 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_pars_file(char *line, t_parse *parse)
{
	int len;

	len = 0;
	if (!(parse->tab = ft_strsplit(line, ' ')))
		return (-1);
	len = ft_strtablen(parse->tab);
	if (parse->len_previous == 0)
		parse->len_previous = len;
	if ((ft_check_tab(parse)) < 0)
	{
		ft_deltab(parse->tab);
		return (-1);
	}
	if (len != parse->len_previous)
		return (-1);
	ft_lst_push_back(&(parse->lst), parse->tab, parse->len_previous);
	return (1);
}

static int		ft_start_parsing(t_mlx *mlx, t_parse *parse)
{
	int		ret;
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	while ((ret = get_next_line(mlx->fd, &line)) > 0)
	{
		if ((ft_pars_file(line, parse)) < 0)
			return (-1);
		i++;
		free(line);
		line = NULL;
	}
	parse->nb_line = i;
	return (1);
}

static int		ft_open_file(t_mlx *mlx, char *format)
{
	t_parse	parse;

	ft_bzero(&parse, sizeof(parse));
	if ((mlx->fd = open(format, O_RDONLY)) < 0)
		return (-1);
	if ((ft_start_parsing(mlx, &parse)) == -1)
		return (-1);
	if ((get_data(&parse, mlx) < 0))
			return (-1);
	ft_lstdelete(&parse);
	close(mlx->fd);
	return (1);
}

static int		ft_init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init(mlx->ptr);
	if (!(mlx->win = mlx_new_window(mlx->ptr, SIZE_W, SIZE_H, "fdf")))
		return (-1);
	mlx->img.pt_image = mlx_new_image(mlx->ptr, SIZE_W, SIZE_H);
	mlx->img.data = (int*)mlx_get_data_addr(mlx->img.pt_image, &mlx->img.bpp,
			&mlx->img.size_l, &mlx->img.endian);
	mlx_key_hook(mlx->win, ft_keyboard, mlx);
	mlx_loop(mlx->ptr);
	return (1);
}

int				main(int argc, char **argv)
{
	t_mlx		mlx;

	ft_bzero(&mlx, sizeof(t_mlx));
	if (argc != 2)
	{
		ft_putendl("wrong number of arguments");
		return (-1);
	}
	if ((ft_open_file(&mlx, argv[1])) == -1)
	{
		ft_putendl("file isn't valid");
		return (-1);
	}
	if (!(ft_init_mlx(&mlx)))
	{
		free_pt(&mlx.pt);
		ft_putendl("the opening went wrong");
		return (-1);
	}
	free_pt(&mlx.pt);
	return (0);
}
