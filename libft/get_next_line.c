/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:20:56 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/20 17:29:05 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		read_file(int fd, t_gnl *gnl)
{
	char	*buf;

	if (gnl->flag)
		return (1);
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((gnl->ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[gnl->ret] = '\0';
		gnl->tmp = gnl->str;
		gnl->str = gnl->tmp ? ft_strjoin(gnl->tmp, buf) : ft_strdup(buf);
		if (!(gnl->str))
			return (-1);
		free(gnl->tmp);
	}
	free(buf);
	return (gnl->ret);
}

void	find_after_cut(t_gnl *gnl)
{
	gnl->i = 0;
	while (gnl->str[gnl->i] != '\n' && gnl->str[gnl->i])
		gnl->i++;
	if (gnl->str[gnl->i] == '\n')
		gnl->flag = 1;
	else
		gnl->flag = 0;
}

int		line_and_cut(int fd, t_gnl *gnl, char **line)
{
	gnl->i = 0;
	while (gnl->str[gnl->i] != '\n' && gnl->str[gnl->i] != '\0')
		gnl->i++;
	if (gnl->str[gnl->i] == '\n')
	{
		if (!(*line = ft_strsub(gnl->str, 0, gnl->i)))
			return (-1);
		gnl->tmp = gnl->str;
		if (!(gnl->str = ft_strdup(gnl->tmp + gnl->i + 1)))
			return (-1);
		free(gnl->tmp);
		find_after_cut(gnl);
		return (1);
	}
	gnl->flag = 0;
	if ((read_file(fd, gnl)) > 0)
		line_and_cut(fd, gnl, line);
	else if (gnl->str && gnl->str[0])
	{
		if (!(*line = ft_strdup(gnl->str)))
			return (-1);
		ft_strdel(&gnl->str);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	gnl;
	int				read;

	if (fd < 0 || line == NULL)
		return (-1);
	if (*line == NULL || (gnl.fd != fd))
	{
		if (gnl.str)
			ft_strdel(&gnl.str);
		ft_memset(&gnl, 0, sizeof(t_gnl));
	}
	gnl.fd = fd;
	read = read_file(fd, &gnl);
	if (read == 0 && gnl.str && gnl.str[0])
	{
		if (!(*line = ft_strdup(gnl.str)))
			return (-1);
		ft_strdel(&gnl.str);
		return (1);
	}
	if (read <= 0)
		return (read);
	return (line_and_cut(fd, &gnl, line));
}
