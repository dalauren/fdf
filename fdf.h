/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:56:01 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/26 14:09:53 by dalauren         ###   ########.fr       */
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

# define SIZE_X 900
# define SIZE_Y 700

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_parse
{
	int				len;
	int				len_previous;
	struct s_list	*lst;
	char			**tab;
}					t_parse;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	int				fd;
}					t_mlx;

int			ft_check_tab(t_parse *parse);
size_t		ft_strtablen(char **tab);

#endif
