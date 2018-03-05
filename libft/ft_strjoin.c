/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:31:32 by vpoccard          #+#    #+#             */
/*   Updated: 2018/01/04 21:41:35 by vpoccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		taille;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	taille = ft_strlen(s1) + ft_strlen(s2);
	if ((fresh = (char *)malloc(sizeof(char) * (taille + 1))) == NULL)
		return (NULL);
	i = 0;
	ft_strcpy(fresh, s1);
	ft_strcat(fresh, s2);
	return (fresh);
}
