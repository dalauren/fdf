/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:39:29 by vpoccard          #+#    #+#             */
/*   Updated: 2017/11/22 20:28:00 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_int_len(int n)
{
	int q;
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		q = n % 10;
		q = n - q;
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		q;
	int		len;
	char	*toa;

	len = ft_int_len(n);
	toa = (char *)malloc(sizeof(char) * (len + 1));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0 || !toa)
		return (ft_strdup("0"));
	if (n < 0)
	{
		toa[0] = '-';
		n = -n;
	}
	toa[len] = '\0';
	while (n > 0)
	{
		toa[len - 1] = n % 10 + '0';
		q = n % 10;
		n = n - q;
		n = n / 10;
		len--;
	}
	return (toa);
}
