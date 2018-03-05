/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:48:20 by vpoccard          #+#    #+#             */
/*   Updated: 2018/03/03 15:16:37 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_filsave(int fd, t_point *var)
{
	var->ret = read(fd, var->buf, BUFF_SIZE);
	var->buf[var->ret] = '\0';
	var->tmp = var->save;
	var->save = ft_strjoin(var->save, var->buf);
	ft_strdel(&var->tmp);
	var->pnt_n = ft_strchr(var->save, '\n');
	return (var->save);
}

int			ft_withoutn(t_point *var, char **line)
{
	if (!var->pnt_n && var->ret == 0 && var->i == 0 &&
			(ft_strcmp(var->save, "") != 0))
	{
		var->i += 1;
		if (!(*line = ft_strnew(BUFF_SIZE)))
			return (-1);
		if (!(*line = ft_strdup(var->save)))
			return (-1);
		return (1);
	}
	return (0);
}

int			ft_filline(t_point *var, char **line)
{
	var->pnt_n = ft_strchr(var->save, '\n');
	if (var->pnt_n)
	{
		*var->pnt_n = 00;
		if (!(*line = ft_strdup(var->save)) ||
				!(ft_memmove(var->save, var->pnt_n + 1,
						ft_strlen(var->pnt_n + 1) + 1)))
			return (-1);
		return (1);
	}
	return (0);
}

static int	ft_free_var(t_point *var)
{
	if (var->tmp != NULL)
		free(var->tmp);
	if (var->pnt_n != NULL)
		free(var->pnt_n);
	if (var->save != NULL)
		free(var->pnt_n);
	if (var->buf != NULL)
		free(var->pnt_n);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static	t_point		var;

	if (var.i != 0 && var.ret == 0)
		ft_memset(&var, 0, sizeof(t_point));
	if (!(var.buf = ft_strnew(BUFF_SIZE)) || !line || fd < 0)
		return (-1);
	if (!var.save)
		var.save = ft_strnew(0);
	var.ret = 1;
	while (var.ret > 0)
	{
		ft_filsave(fd, &var);
		if (ft_filline(&var, line) == 1)
			return (1);
	}
	if (ft_withoutn(&var, line) == 1)
		return (1);
	if (var.ret == 0)
	{
		ft_memset(&var, 0, sizeof(t_point));
		ft_free_var(&var);
	}
	return (var.ret);
}
