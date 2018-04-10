/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:56:01 by dalauren          #+#    #+#             */
/*   Updated: 2018/04/10 16:31:20 by dalauren         ###   ########.fr       */
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
	int					x;
	int					y;
	int					z;
}						t_point;

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
	void				*pt_image;
	int					*data;
	int					size_l;
	int					bpp;
	int					endian;
}						t_img;
typedef struct			s_mlx
{
	void				*ptr;
	void				*win;
	int					fd;
	int					key;
	t_img				img;
	t_point				***pt;
}						t_mlx;

void					ft_lstdelete(t_parse *parse);
void					free_pt(t_point ****pt);
int						ft_check_tab(t_parse *parse);
int						ft_keyboard(int key, t_mlx *mlx);
int						get_data(t_parse *parse, t_mlx *mlx);
int						start_map(t_mlx *mlx);
size_t					ft_strtablen(char **tab);

#endif
