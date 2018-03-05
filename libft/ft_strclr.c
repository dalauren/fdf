/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:26:58 by vpoccard          #+#    #+#             */
/*   Updated: 2017/11/21 18:30:07 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int i;

	if (s == NULL)
		return ((void)NULL);
	i = 0;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
	s[i] = '\0';
}
