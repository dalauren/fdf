/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:20:53 by vpoccard          #+#    #+#             */
/*   Updated: 2017/11/15 22:16:13 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long result;

	result = n;
	if (result < 0)
	{
		write(fd, "-", 1);
		result = -result;
	}
	if (result > 9)
	{
		ft_putnbr_fd(result / 10, fd);
		ft_putnbr_fd(result % 10, fd);
	}
	if (result < 9 || result == 9)
		ft_putchar_fd(result + '0', fd);
}
