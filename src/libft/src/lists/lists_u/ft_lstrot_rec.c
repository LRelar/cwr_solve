/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrot_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:35:39 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:22:17 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function recursively rotates t_list chain.
**	Not recommended to be used on a long chain as it can overflow stack or
**	slow down the programm.
**	WARNING! UNSAFE FUNCTION! Function does not check if there is any t_list
**	chain (cuz it lower it's moderate prudctivity even more).
**	HOW TO USE:
**	*alst = ft_lstrot_rec(*alst, NULL);
**	Where t_list **alst - a pointer, ponting to the pointer of the chain head.
*/

t_list		*ft_lstrot_rec(t_list *current, t_list *prev)
{
	t_list	*new_head;

	if (current->next)
	{
		new_head = ft_lstrot_rec(current->next, current);
		current->next = prev;
		return (new_head);
	}
	current->next = prev;
	return (current);
}
