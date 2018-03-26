/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 07:55:11 by dalauren          #+#    #+#             */
/*   Updated: 2017/11/17 07:55:13 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *robin;
	t_list *batman;

	batman = *alst;
	while (batman != NULL)
	{
		robin = batman->next;
		ft_lstdelone(&batman, del);
		batman = robin;
	}
	*alst = NULL;
}
