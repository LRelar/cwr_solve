/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstwipe_ring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:08:38 by mschimme          #+#    #+#             */
/*   Updated: 2019/12/08 17:55:14 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This version tries to wipe whole chain, given the chain is solid (both
**	next and prev links adress to members of the chain).
**	WARNING! Infinite loop will occur if given chain is looped!
*/

void		ft_dlstwipe_ring(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*sub;
	t_dlist *ptr;

	if (!alst)
		return ;
	ptr = (*alst)->prev;
	while (*alst != ptr)
	{
		sub = (*alst)->next;
		ft_dlstdelone(alst, del);
		*alst = sub;
	}
	ft_dlstdelone(alst, del);
	*alst = NULL;
}
