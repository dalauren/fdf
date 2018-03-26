/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 12:34:08 by dalauren          #+#    #+#             */
/*   Updated: 2017/12/12 11:02:04 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 10000000

typedef struct	s_gnl_struct
{
	int			i;
	int			ret;
	int			flag;
	int			fd;
	char		*str;
	char		*tmp;
}				t_gnl;

int				get_next_line(const int fd, char **line);
int				line_and_cut(int fd, t_gnl *gnl, char **line);

#endif
