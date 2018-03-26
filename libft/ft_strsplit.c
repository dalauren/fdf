/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 08:46:15 by dalauren          #+#    #+#             */
/*   Updated: 2017/11/17 10:48:50 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_word(char *str, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			word++;
		while (str[i] != c && str[i])
			i++;
	}
	return (word);
}

static char		*fill_tab(char *s, char c, int *i)
{
	char	*str;
	int		j;

	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	j = 0;
	while (s[*i] != c && s[*i])
	{
		str[j] = s[*i];
		j++;
		*i += 1;
	}
	str[j] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_word((char*)s, c) + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (k < nb_word((char *)s, c) && s[i])
	{
		tab[k] = fill_tab((char*)s, c, &i);
		k++;
	}
	tab[k] = 0;
	return (tab);
}
