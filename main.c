/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:59:52 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/29 14:51:23 by dalauren         ###   ########.fr       */
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
		free(parse->tab);
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
	if ((get_data(&parse) < 0))
			return (-1);
	return (1);
}

/*static int		ft_init_mlx(t_mlx *mlx)*/
/*{*/
	/*mlx->ptr = mlx_init(mlx->ptr);*/
	/*if (!(mlx->win = mlx_new_window(mlx->ptr, SIZE_X, SIZE_Y, "fdf")))*/
		/*return (-1);*/
	/*mlx_loop(mlx->ptr);*/
	/*return (1);*/
/*}*/

int				main(int argc, char **argv)
{
	t_mlx mlx;

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
	/*if (!(ft_init_mlx(&mlx)))*/
	/*{*/
		/*ft_putendl("the opening went wrong");*/
		/*return (-1);*/
	/*}*/
	return (0);
} // don't forget to free the lst
