/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:08:38 by mschimme          #+#    #+#             */
/*   Updated: 2019/12/08 17:48:35 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This version deletes only the part of chain, starting from *alst.
**	In oreder to wipe whole chain it is supposed to receive the beginning of the
**	chain.
**	WARNING! Sig.Abrot is imminent if chain is looped!
*/

void		ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*sub;

	if (!alst)
		return ;
	while (*alst)
	{
		sub = (*alst)->next;
		ft_dlstdelone(alst, del);
		*alst = sub;
	}
	*alst = NULL;
}
