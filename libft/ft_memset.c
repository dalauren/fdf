/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:17:42 by vpoccard          #+#    #+#             */
/*   Updated: 2017/11/21 18:22:48 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *d;

	if (len == 0)
		return (b);
	d = (unsigned char *)b;
	while (len--)
	{
		*d = (unsigned char)c;
		if (len)
			d++;
	}
	return (b);
}
