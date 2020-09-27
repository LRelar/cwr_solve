/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:40:13 by mschimme          #+#    #+#             */
/*   Updated: 2019/03/06 20:07:45 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function f supposed to create new instance chain on its on. Yet it supposed
** to clear the sh't up after malloc fail on its own.
** static void	ft_clearjunk(t_list *start)
** {
** 	t_list	*sub;
** 	while (start)
** 	{
** 		sub = start->next;
** 		ft_lstdelone(&start, ft_del);
** 		start = sub;
** 	}
** }
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;
	t_list	*previous;

	start = NULL;
	if (!lst || !f)
		return (NULL);
	start = f(lst);
	previous = start;
	lst = lst->next;
	while (lst)
	{
		if (!(new = f(lst)))
			return (NULL);
		previous->next = new;
		previous = previous->next;
		lst = lst->next;
	}
	return (start);
}
