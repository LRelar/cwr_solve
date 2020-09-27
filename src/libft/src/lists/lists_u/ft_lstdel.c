/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:08:38 by mschimme          #+#    #+#             */
/*   Updated: 2019/12/08 17:36:01 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*sub;

	if (!alst)
		return ;
	while (*alst)
	{
		sub = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = sub;
	}
	*alst = NULL;
}
