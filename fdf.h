/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:56:01 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/24 20:03:39 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "./libft/libft.h"
# include "./libft/keyboard.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define SIZE_W 900
# define SIZE_H 700

typedef struct			s_point
{
	float				x;
	float				y;
	float				z;
}						t_point;

typedef struct			s_line
{
	t_point				p1;
	t_point				p2;
}						t_line;

typedef struct			s_parse
{
	int					len;
	int					nb_line;
	int					len_previous;
	struct s_list		*lst;
	char				**tab;
}						t_parse;

typedef struct			s_img
{
	void				*img_ptr;
	char				*img_str;
	int					endian;
	int					s_l;
	int					bpp;
}						t_img;

typedef struct			s_mlx
{
	void				*ptr;
	void				*win;
	float				scale;
	int					fd;
	float				div;
	float				size_w;
	float				size_h;
	char				*format;
	int					color;
	int					size_line;
	int					nb_line;
	int					key;
	int					z_min;
	int					z_max;
	int					z_scale;
	t_point				***pt;
	t_img				img;
}						t_mlx;

void					ft_lstdelete(t_parse *parse);
void					free_pt(t_point ****pt);
void					line(t_line l, t_mlx *mlx, int color);
void					modif_height(int key, t_mlx *mlx);
void					modif_place(int key, t_mlx *mlx);
void					transform_point(t_mlx *mlx);
void					ft_zoom(int key, t_mlx *mlx);
void					zoom_plus(t_mlx *mlx);
void					zoom_less(t_mlx *mlx);
void					reset_map(t_mlx *mlx);
void					put_pixel(int x, int y, unsigned int color, t_img *img);
void					get_z(int z, t_mlx *mlx);
int						ft_open_file(t_mlx *mlx, char *format);
int						ft_check_tab(t_parse *parse);
int						ft_keyboard(int key, t_mlx *mlx);
int						ft_init_mlx(t_mlx *mlx);
int						ft_mouse(int button, int x, int y, void *param);
int						get_data(t_parse *parse, t_mlx *mlx);
int						draw_map(t_mlx *mlx);
int						start_map(t_mlx *mlx);
size_t					ft_strtablen(char **tab);

#endif
