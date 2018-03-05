/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:01:16 by vpoccard          #+#    #+#             */
/*   Updated: 2017/11/21 19:14:38 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f) (char))
{
	size_t	i;
	char	*str;
	int		len;

	i = 0;
	len = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
	{
		len++;
		i++;
	}
	i = 0;
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}
