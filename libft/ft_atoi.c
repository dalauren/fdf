/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:28:49 by vpoccard          #+#    #+#             */
/*   Updated: 2017/11/21 18:15:14 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		neg;

	i = 0;
	result = 0;
	neg = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	if (neg == 1)
		return (-result);
	else
		return (result);
}
