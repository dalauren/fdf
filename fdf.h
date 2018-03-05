/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:08:50 by vpoccard          #+#    #+#             */
/*   Updated: 2018/02/27 04:31:29 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include "libft/keyboard.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define WIDTH 1500
# define HEIGHT 1300

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*file;
	char			**tab;
	int				**tabi;
	char			*pnt_n;
	int				nbl;
	int				nbc;
	int				nbc1;
	int				**map;
	int				fd;
	int				width;
	int				height;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				check;
	unsigned long	color;
	int				imax;
}					t_mlx;

typedef struct		s_splitint
{
	int				i;
	int				j;
	int				ret;
	char			*line;
	char			**tab;
}					t_splitint;

typedef struct		s_xayaxbyb
{
	int				xa;
	int				ya;
	int				xb;
	int				yb;
	int				nxtx;
	int				nxty;
}					t_xayaxbyb;

typedef struct		s_bresenham
{
	int				i;
	int				j;
	int				m;
	int				n;
	int				k;
	int				l;
}					t_bresenham;

void				free_me(int **map, int max_i);
int					ft_or(int argc, char **argv, t_mlx *mlx);
int					ft_color(t_mlx *mlx, int nxty, int nxtx);
int					ft_init_mlx(t_mlx *mlx);
int					ft_get_nb(t_mlx *mlx, char *line);
int					ft_tabs(t_mlx *mlx);
int					ft_parse(t_mlx *mlx, char **argv);
void				ft_fdf(t_mlx *mlx);
int					ft_keyboard(int key, t_mlx *mlx);
void				ft_fdf_key(t_mlx *mlx);
void				ft_map_line(t_mlx *mlx, int x, int y);
void				free_tab(char **tab, int max_i);

#endif
