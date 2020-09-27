/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:01:21 by mschimme          #+#    #+#             */
/*   Updated: 2019/12/10 22:22:52 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstdelone(t_dlist **alst, void (*del)(void*, size_t))
{
	t_dlist	*ptr;

	if (!alst || !(*alst))
		return ;
	if (del)
		del((*alst)->content, (*alst)->content_size);
	ptr = *alst;
	ptr->content = NULL;
	if (ptr->prev)
		ptr->prev->next = ptr->next;
	if (ptr->next)
		ptr->next->prev = ptr->prev;
	*alst = (t_dlist *)((ptr->next != ptr) * (size_t)ptr->next);
	free(ptr);
}
