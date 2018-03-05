/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 22:33:40 by vpoccard          #+#    #+#             */
/*   Updated: 2017/11/21 19:40:21 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while ((src[i] != 0) && (i < len))
	{
		dst[i] = src[i];
		i++;
	}
	if (i < len)
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
	return (dst);
}
