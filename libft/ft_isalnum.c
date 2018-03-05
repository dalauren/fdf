/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:40:42 by vpoccard          #+#    #+#             */
/*   Updated: 2017/11/21 18:16:11 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	int alpha;
	int digit;

	alpha = 0;
	digit = 0;
	if (c >= '0' && c <= '9')
		digit = 1;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		alpha = 1;
	if (digit == 1 || alpha == 1)
		return (1);
	else
		return (0);
}
