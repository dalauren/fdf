/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:54:42 by vpoccard          #+#    #+#             */
/*   Updated: 2017/11/21 18:25:02 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long result;

	result = n;
	if (result < 0)
	{
		write(1, "-", 1);
		result = -result;
	}
	if (result > 9)
	{
		ft_putnbr(result / 10);
		ft_putnbr(result % 10);
	}
	if (result < 9)
		ft_putchar(result + '0');
	if (result == 9)
		ft_putchar(result + '0');
}
