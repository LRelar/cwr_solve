/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cyclist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 23:09:01 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 01:04:12 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
** status_quo is used in order to detect if ft_lstnew_r failed to allocate
** memory for new t_vasa (t_list) entry.
** counter is used to calculate size of array, that gonna be created
** after we finished registring -dump entries, as head will alway store
** their total amount.
*/

void			ft_add_cyclist(t_vasa **head, long long number)
{
	t_vasa			*status_quo;
	static size_t	counter;

	status_quo = *head;
	ft_lstadd((t_list **)head, ft_lstnew_r(NULL, 0));
	if (*head == status_quo)
	{
		ft_err_malloc("new_head for cyc_to_dump", \
									"ft_lstnew_r invoked in ft_add_cyclist");
		ft_manage_world(NULL);
	}
	(*head)->gen.cyc_sol = (size_t)number;
	(*head)->content_size = ++counter;
}
