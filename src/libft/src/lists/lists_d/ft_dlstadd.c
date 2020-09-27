/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:25:24 by mschimme          #+#    #+#             */
/*   Updated: 2019/12/08 18:09:03 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstadd(t_dlist **alst, t_dlist *new, uint8_t flag)
{
	if (!new || !alst)
		return ;
	if (*alst)
	{
		if ((*alst)->next)
			(*alst)->next->prev = new;
		new->next = (*alst)->next;
		(*alst)->next = new;
		new->prev = *alst;
	}
	else
	{
		if (flag)
		{
			new->next = new;
			new->prev = new;
		}
	}
	*alst = new;
}
